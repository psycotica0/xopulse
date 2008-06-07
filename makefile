.PHONY: clean all

all : instruction.o sprite.o manager.o

instruction.o : instruction.cpp instruction.h sprite.h
	gcc -c instruction.cpp -o instruction.o

sprite.o : sprite.cpp sprite.h
	gcc -c sprite.cpp -o sprite.o

manager.o : manager.cpp manager.h instruction.h
	gcc -c manager.cpp -o manager.o

clean : 
	rm instruction.o
	rm sprite.o
	rm manager.o

