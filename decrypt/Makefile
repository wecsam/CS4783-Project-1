CC=g++
CFLAGS=-Wall -Werror -std=c++11
EXECUTABLE_NAME=Tsai-Poch-decrypt

%.o: %.cpp Bigrams.h 
	$(CC) $< -c -o $@ $(CFLAGS)

build: main.o 
	$(CC) main.o -o $(EXECUTABLE_NAME) $(CFLAGS)

run:
	./$(EXECUTABLE_NAME)

tests: Bigrams.o
	$(CC) Bigrams.o bigrams-tester.cpp -o bigrams-tester $(CFLAGS)
