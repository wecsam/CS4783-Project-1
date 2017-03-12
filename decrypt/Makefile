CC=g++
CFLAGS=-Wall -Werror -std=c++11 -O3
EXECUTABLE_NAME=Tsai-Poch-decrypt
PARTS=\
	EnglishWords\
	Plaintext\
	PlaintextDictionary\

%.o: %.cpp $(foreach part, $(PARTS), $(part).h )
	$(CC) $< -c -o $@ $(CFLAGS)

build: $(foreach part, $(PARTS), $(part).o ) main.o
	$(CC) $(foreach part, $(PARTS), $(part).o ) main.o -o $(EXECUTABLE_NAME) $(CFLAGS)

run:
	@./$(EXECUTABLE_NAME)

clean:
	test -f $(EXECUTABLE_NAME) && rm $(EXECUTABLE_NAME); true
	test -f main.o && rm main.o; true
	test -f .Tsai-Pock-key.bin && rm .Tsai-Pock-key.bin; true
	$(foreach part,$(PARTS),test -f $(part).o && rm $(part).o;) true

tests: Bigrams.o
	$(CC) Bigrams.o bigrams-tester.cpp -o bigrams-tester $(CFLAGS)

random-ciphertext:
	@(cd ../frequencies; ./random_message.py) | (cd ../cipher-demo/; ./cipher-demo 2>/dev/null)
