.PHONY: clean all

all : instruction.o sprite.o manager.o

instruction.o : instruction.cpp instruction.h
	gcc -c -I /opt/local/include/cairo instruction.cpp -o instruction.o

sprite.o : sprite.cpp sprite.h
	gcc -c -I /opt/local/include/cairo sprite.cpp -o sprite.o

manager.o : manager.cpp manager.h
	gcc -c -I /opt/local/include/cairo manager.cpp -o manager.o

clean : 
	rm instruction.o
	rm sprite.o
	rm manager.o

