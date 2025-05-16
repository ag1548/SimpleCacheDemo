.PHONY: run compile

run:
	@${MAKE} --no-print-directory compile
	@./main
	@rm main

compile: main.cpp
	@g++ -o main main.cpp
