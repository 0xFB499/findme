SHELL=/bin/bash

build: findme.c
	@echo "BUILDING"
	gcc ./findme.c -o find.me

clean:
	\rm -f ./find.me

test: build
	@echo "TEST: comparing output './find.me ./test.bin' with ./expected.txt "
	@if [[ $(./find.me ./test.bin) -eq $(cat ./expected.txt) ]]; then 	\
		echo "TEST PASSED"; 						\
	else 									\
		echo "TEST FAILED :c";						\
	fi								
	
