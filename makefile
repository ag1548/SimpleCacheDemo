.PHONY: run compile

run:
	@${MAKE} --no-print-directory compile
	@./main
	@rm main

compile: main.cpp
	@g++ -o main main.cpp

compile_to_assembly: main.cpp
	@g++ -o main.S main.cpp -S

compile_to_object: main.cpp
	@g++ -o main.o main.cpp -c
	@objdump -D main.o > main.o.dis
	