CC=g++
CFLAGS=-Wall -Werror -std=c++11 -g -fvar-tracking
EXECUTABLE_NAME=Tsai-Poch-decrypt
PARTS=\
	Bigrams\
	Plaintext\
	PlaintextDictionary\
	ProbabilityDistribution\

%.o: %.cpp $(foreach part, $(PARTS), $(part).h )
	$(CC) $< -c -o $@ $(CFLAGS)

build: $(foreach part, $(PARTS), $(part).o ) main.o
	$(CC) $(foreach part, $(PARTS), $(part).o ) main.o -o $(EXECUTABLE_NAME) $(CFLAGS)

run:
	@./$(EXECUTABLE_NAME)

clean:
	-rm $(EXECUTABLE_NAME)
	-rm main.o
	$(foreach part, $(PARTS), rm $(part).o; )

tests: Bigrams.o
	$(CC) Bigrams.o bigrams-tester.cpp -o bigrams-tester $(CFLAGS)
