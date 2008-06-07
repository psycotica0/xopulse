.PHONY: clean all

all : instruction.o sprite.o manager.o atManager.o

instruction.o : instruction.cpp instruction.h sprite.h
	g++ -c instruction.cpp -o instruction.o

sprite.o : sprite.cpp sprite.h
	g++ -c sprite.cpp -o sprite.o

manager.o : manager.cpp manager.h instruction.h
	g++ -c manager.cpp -o manager.o

atManager.o : manager.o atManager.h atManager.cpp
	g++ -c atManager.cpp -o atManager.o

clean : 
	rm instruction.o
	rm sprite.o
	rm manager.o
	rm atManager.o

