#include "instruction.h"

/*
when: This function just returns the number of milliseconds after the start this event occurs at
*/
int Instruction::when() {
	return At;
}

/*
SetInstruction: This is a constructor for the Setinstruction class
	This creates a set instruction with the given parameters.

	target: This is the sprite the instruction is executed on.
	When: This is the time the instruction occurs at.
	Values: This is a map of the different paraeters and their values.
*/
SetInstruction::SetInstruction (Sprite* target,int When, std::map<char *, int>* Values){
	Target=target;
	Parameters = Values;
	At=When;
	return;
}

/*
perform: This function makes the changes it was set to make.
*/
void SetInstruction::perform () {
	//Do it!
	Target->setParameters(Parameters);
	return;
}
