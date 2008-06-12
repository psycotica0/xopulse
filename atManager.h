#ifndef _ATMANAGER_H_
#define _ATMANAGER_H_

#include "manager.h"
#include "instruction.h"
#include <string>
#include "global.h"

/*
AtManager: This class is in charge of managing input from AtFiles.
*/
class AtManager: public Manager {
	protected:
		//This list holds the current instructions as it's being formed.
		//It's sorted by key, so it should do fast insertions, and I should be able to just make it a queue later.
		std::multimap<int , Instruction*> TempInstruction;
		//This function is called to form "Set" type instructions
		void Set(int At, char* Sprite, char* Parameters);
		//This function is called to form "Change" type instructions
		void Change(int At, char* Sprite, char*Parameters, int Duration);
		//This function should break up a comma separated list of parameters and values into a map
		std::map<PARAM_MAP> BreakList ( char*);
	public:
		//This function takes in a file and parses it into a sorted queue of instructions.
		void parseFile(char *);
};
#endif
