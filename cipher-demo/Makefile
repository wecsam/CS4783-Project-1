CC=g++
CFLAGS=-Wall -Werror -std=c++11

%.o: %.cpp MessageCharacter.h Key.h
	$(CC) $< -c -o $@ $(CFLAGS)

main: cipher-demo.o MessageCharacter.o Key.o
	$(CC) cipher-demo.o MessageCharacter.o Key.o -o cipher-demo

keygen:
	$(CC) keygen.cpp -o keygen $(CFLAGS)

run:
	./cipher-demo

run-keygen:
	./keygen

clean:
	rm *.o keygen cipher-demo
