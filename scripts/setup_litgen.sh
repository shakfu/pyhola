
echo "creating virtualenv .venv for litgen"
virtualenv .venv
source .venv/bin/activate
pip install "litgen@git+https://github.com/pthom/litgen"
