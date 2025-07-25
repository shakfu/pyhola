CWD=`pwd`
NAME=adaptagrams
THIRDPARTY=${CWD}/thirdparty
PREFIX=${THIRDPARTY}/${NAME}


get_adaptagrams() {
	echo "update from ${NAME} fork"	
	mkdir -p build ${THIRDPARTY} && \
		cd build && \
		if [ ! -d "${NAME}" ]; then
			git clone --depth 1 https://github.com/shakfu/adaptagrams.git
		fi && \
		cd ${NAME} && \
		make install && \
		mv build/install ${PREFIX}
		cd ${CWD}
}

remove_current() {
	echo "remove current"
	rm -rf build thirdparty
}


main() {
	remove_current
	get_adaptagrams
}

main


