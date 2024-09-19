#!/usr/bin/env python3
"""header_utils.py

Provides `HeaderProcessor`, a utility class to recursively process header
declarations for [binder](https://github.com/RosettaCommons/binder).

Default header transformations:
    -> change_quotes_to_pointy_brackets
    -> change_relative_to_absolute_header_references

Optional header transformations
    -> change_pragma_one_to_header_guards

Additional Features:
    - generate graph of header references in [png|svg|pdf|dot] format

repo: <https://github.com/shakfu/header_utils>

"""
import argparse
import logging
import os
import re
import shutil
import sys
from typing import ClassVar

try:
    import graphviz  # type: ignore
    HAVE_GRAPHVIZ = True
except ImportError:
    HAVE_GRAPHVIZ = False


__version__ = "0.1.1"

__all__ = ['HeaderProcessor']

DEBUG = False

class CustomFormatter(logging.Formatter):
    """custom formatter class to add colors to logging"""

    white = "\x1b[97;20m"
    GREY = "\x1b[38;20m"
    GREEN = "\x1b[32;20m"
    CYAN = "\x1b[36;20m"
    YELLOW = "\x1b[33;20m"
    RED = "\x1b[31;20m"
    RED_BOLD = "\x1b[31;1m"
    RESET = "\x1b[0m"
    fmt = "{}%(levelname)s{} - %(message)s"

    FORMATS = {
        logging.DEBUG: fmt.format(GREY, RESET),
        logging.INFO: fmt.format(GREEN, RESET),
        logging.WARNING: fmt.format(YELLOW, RESET),
        logging.ERROR: fmt.format(RED, RESET),
        logging.CRITICAL: fmt.format(RED_BOLD, RESET),
    }

    def format(self, record):
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt, datefmt="%H:%M:%S")
        return formatter.format(record)


__handler = logging.StreamHandler()
__handler.setFormatter(CustomFormatter())
logging.basicConfig(
    level=logging.DEBUG if DEBUG else logging.INFO,
    handlers=[__handler]
)

class HeaderProcessor:
    """Recursively processes header declarations for binder

    Args:
        input_dir        (str): Directory containing source headers.
        output_dir       (str): Directory for changed headers.
        header_endings ([str]): Header endings to apply transformations to.
                                (defaults to [".h", ".hpp", ".hh"])
        header_guards   (bool): Activate `#pragma once` to header guards transform.
        dry_run         (bool): Process headers without changing anything.
        force_overwrite (bool): Force overwrite output_dir if it already exists.
    """

    PATTERN: ClassVar = re.compile(r"^#include \"(.+)\"")
    DEFAULT_HEADER_ENDINGS: ClassVar[list[str]] = [".h", ".hpp", ".hh"]

    def __init__(
        self,
        input_dir: str,
        output_dir: str,
        header_endings: list[str] = None,  # type: ignore
        header_guards: bool = False,
        dry_run: bool = False,
        force_overwrite: bool = False,
    ):
        self.input_dir = input_dir
        self.output_dir = output_dir
        self.header_endings = (
            header_endings if header_endings else self.DEFAULT_HEADER_ENDINGS
        )
        self.header_guards = header_guards
        self.dry_run = dry_run
        self.force_overwrite = force_overwrite
        if HAVE_GRAPHVIZ:
            self.graph = graphviz.Digraph("dependencies", comment="Header References")
        else:
            self.graph = None
        self.log = logging.getLogger(self.__class__.__name__)
        if not os.path.exists(input_dir):
            self.log.error("provided input_dir argument '%s' does not exist", input_dir)
            sys.exit(1)

    def process_headers(self):
        """Main process to recursively transform copy of input_dir headers
        and write them to output_dir.

        Does not write changes if .dry_run is True
        """
        self.log.info("START: transforming headers in '%s' to '%s'",
            self.input_dir, self.output_dir)
        if self.dry_run:
            self.log.info("DRY-RUN MODE: ON")
        if not self.dry_run:
            if not self.output_dir:
                self.log.warning("Must provide output_dir if dry-run is False")
                sys.exit(1)
            shutil.copytree(self.input_dir, self.output_dir,
                dirs_exist_ok=self.force_overwrite,
            )

        for header_path in self.get_headers():
            base_path = self.get_base_path(header_path)
            self.log.info(base_path)
            with open(header_path, encoding="utf-8") as fopen:
                lines = fopen.readlines()
            _result = self.transform(lines, base_path)
            if not self.dry_run:
                header_path = os.path.join(self.output_dir, base_path)
                with open(header_path, "w", encoding="utf-8") as fwrite:
                    fwrite.writelines(_result)

        self.log.info("END: transforming headers in '%s' to '%s'",
            self.input_dir, self.output_dir)

    def get_headers(self, sort: bool = False, from_output_dir: bool = False) -> list[str]:
        """Retrieve all header files recursively

        Returns a list of header paths.

        Can be optionally sorted and retrieved from output_dir
        """
        if from_output_dir:
            path = self.output_dir
        else:
            path = self.input_dir
        results = []
        for root, _, files in os.walk(path):
            for fname in files:
                if any(fname.endswith(e) for e in self.header_endings):
                    results.append(os.path.join(root, fname))
        if sort:
            return sorted(results)
        return results

    def get_base_path(self, header_path: str) -> str:
        """Returns base path, or the path which follows `self.input_dir`"""
        path = self.input_dir
        if not path.endswith("/"):
            path = f"{path}/"
        return header_path[len(path) :]

    def transform(self, lines: list[str], base_path: str) -> list[str]:
        """Main tranformation pipeline

        Returns a list of header paths.
        """
        _transformers = [
            "normalize_header_include_statements",
        ]
        if self.header_guards:
            _transformers.append("normalize_header_guards")
        for transformer in _transformers:
            lines = getattr(self, transformer)(lines, base_path)
        return lines

    def normalize_header_guards(self, lines: list[str], base_path: str) -> list[str]:
        """Convert '#pragma once' to guarded headers

        Returns a list of header paths.
        """
        _results = []
        name = base_path.replace("/", "_").replace(".", "_").upper()
        for line in lines:
            if line.startswith("#pragma once"):
                line = line.strip()
                replacement = f"#ifndef {name}\n"
                _results.append(replacement)
                define = f"#define {name}\n"
                _results.append(define)
                self.log.info("#pragma once -> guarded headers")
                continue
            _results.append(line)
        _results.append(f"#endif // {name}\n")
        return _results

    def normalize_header_include_statements(self, lines: list[str], base_path: str) -> list[str]:
        """Convert quotes to pointy brackets in an an include statement.

        Returns a list of header paths.
        """
        _result = []
        for line in lines:
            if line.startswith("#include "):
                if line.endswith('"\n'):
                    line = line.strip()
                    abs_ref, abs_include = self.normalize_include_statement(
                        line, base_path
                    )
                    _result.append(abs_include)
                    self.log.info(
                        "  %s -> %s",
                        line.lstrip("#include "),
                        abs_include.strip().lstrip("#include "),
                    )
                    if HAVE_GRAPHVIZ and self.graph:
                        self.graph.edge(base_path, abs_ref)
                    continue
            _result.append(line)
        return _result

    def normalize_include_statement(self, line: str, base_path: str) -> tuple[str, str]:
        """Normalize include statement.

        Changes include statement quotes to pointy brackets and relative header references to absolute ones.
        Returns a tuple pair of absolute reference of the include statement and
        the modified include statement itself.
        """
        match = self.PATTERN.match(line)
        if match:
            rel_ref = match.group(1)
            abs_ref = self.convert_rel_to_abs_path_ref(base_path, rel_ref)
            return (abs_ref, f"#include <{abs_ref}>\n")
        raise ValueError

    def convert_rel_to_abs_path_ref(self, base_path: str, relative_path: str) -> str:
        """Converts relative path to absolute path

        Returns absolute path.
        """
        base_parts = base_path.split("/")
        relative_parts = relative_path.split("/")
        base_parts.pop()
        for part in relative_parts:
            if part == ".":
                continue
            if part == "..":
                base_parts.pop()
            else:
                base_parts.append(part)
        return "/".join(base_parts)

    def list_target_headers(self):
        """Recursively list all headers"""
        headers = self.get_headers()
        for header_path in headers:
            self.log.info(header_path)

    def get_include_statements(
        self, sort: bool = False, from_output_dir: bool = False
    ) -> list[str]:
        """Recursively get all include statements.

        Returns a list of header paths.
        """
        _results = []
        for header in self.get_headers(sort, from_output_dir):
            with open(header, encoding="utf-8") as fopen:
                lines = fopen.readlines()
                for line in lines:
                    if line.startswith("#include "):
                        _results.append(line.strip())
        return _results

    @classmethod
    def commandline(cls):
        """Implements commmandline api"""
        parser = argparse.ArgumentParser(
            description=(
                "Convert headers to a binder friendly format. "
                f"(default: {cls.DEFAULT_HEADER_ENDINGS})"
            ),
            formatter_class=argparse.ArgumentDefaultsHelpFormatter,
        )

        required = option = parser.add_argument

        required("input_dir", help="input include directory containing source headers")

        option("--output_dir", "-o", help="output directory for modified headers")

        option(
            "--header-endings",
            "-e",
            nargs="+",
        )

        option(
            "--header-guards",
            action="store_true",
            help="convert `#pragma once` to header guards",
        )

        option(
            "--dry-run",
            "-d",
            action="store_true",
            help="run in dry-run mode without actual changes",
        )

        option(
            "--force-overwrite",
            "-f",
            action="store_true",
            help="force overwrite output_dir if it already exists",
        )

        option("--list", "-l", action="store_true", help="list target headers only")

        option(
            "--graph",
            "-g",
            help="output path for graphviz graph with format suffix [png|pdf|svg]",
        )

        args = parser.parse_args()

        if args.input_dir:
            app = cls(
                args.input_dir,
                args.output_dir,
                args.header_endings,
                args.header_guards,
                args.dry_run,
                args.force_overwrite,
            )
            if args.list:
                app.list_target_headers()
            else:
                app.process_headers()
                if args.graph and app.graph:
                    app.graph.render(outfile=args.graph)


if __name__ == "__main__":
    HeaderProcessor.commandline()
