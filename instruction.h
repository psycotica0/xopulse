#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "sprite.h"
#include <map>

class Instruction {
	protected:
		//This is a pointer to the target of the instruction.
		Sprite * Target;
		//This is the time the instruction is to be executed at
		int At;
	public:
		//This function will return the time when the command should be executed.
		int when();
		//This is an abstract virtual function that will perform the effects of the instruction on the sprite
		virtual void perform()=0;
};

class SetInstruction : public Instruction {
	protected:
	//This is a map 
	std::map<char *, int> * Parameters;
	public:
	//This constructor takes in a map of parameters and their requested values to set
	SetInstruction (Sprite* ,int, std::map<char *, int>*);
	//This function evokes the change in the sprite
	void perform();
};

#endif
