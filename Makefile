.PHONY: all
all:
	mkdir bin

	cd brute && make
	mv brute/brute bin/brute
	cd brute && make clean

	cd bb && make
	mv bb/main bin/bb
	cd bb && make clean

	cd ga && make
	mv ga/main bin/ga
	cd ga && make clean

.PHONY: clean
clean:
	rm -rf bin
