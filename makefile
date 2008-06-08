.PHONY: clean all test

all : instruction.o sprite.o manager.o atManager.o

instruction.o : instruction.cpp instruction.h sprite.h
	g++ -c instruction.cpp -o instruction.o

sprite.o : sprite.cpp sprite.h
	g++ -c sprite.cpp -o sprite.o

manager.o : manager.cpp manager.h instruction.h
	g++ -c manager.cpp -o manager.o

atManager.o : manager.o atManager.h atManager.cpp
	g++ -c atManager.cpp -o atManager.o

test.e : all test.cpp
	g++ test.cpp atManager.o manager.o sprite.o instruction.o -o test.e

test: test.e
	./test.e

clean : 
	rm -f instruction.o
	rm -f sprite.o
	rm -f manager.o
	rm -f atManager.o
	rm -f test.e

