#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "sprite.h"
#include <map>
#include <string>
#include "global.h"

/*
Instruction: This is a base class for all instruction objects
	Because perform has been made an abstract virual base class, an instruction object can never be made
		This is ok though, because pointers to it can, and that's all this instruction is for anyway.
	It mostly just implements functions and parameters that all instructions need.
*/
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

/*
SetInstruction: This is an instruction that sets parameters in a sprite
*/
class SetInstruction : public Instruction {
	protected:
	//This is a map 
	std::map<PARAM_MAP> * Parameters;
	public:
	//This constructor takes in a map of parameters and their requested values to set
	SetInstruction (Sprite* ,int, std::map<PARAM_MAP>*);
	//This function evokes the change in the sprite
	void perform();
};
/*
ChangeInstruction: This is an instruction that sets changes in parameters in a sprite
*/
class ChangeInstruction : public Instruction {
	protected:
	//This is a map 
	std::map<PARAM_MAP> * Parameters;
	//This holds the length of time the change occurs over
	int Duration;
	public:
	//This constructor takes in a map of parameters and their requested values to set
	ChangeInstruction (Sprite* ,int, std::map<PARAM_MAP>*,int);
	//This function evokes the change in the sprite
	void perform();
};

#endif
