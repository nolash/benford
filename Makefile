all: test

dir:
	mkdir -p .build

test: libs
	make -C src/test test

libs: dir
	make -C src libs	

clean:
	rm -rf .build
