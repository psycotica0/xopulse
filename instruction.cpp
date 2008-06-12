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
SetInstruction::SetInstruction (Sprite* target,int When, std::map<PARAM_MAP>* Values){
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

/*
ChangeInstruction: This is a constructor for the ChangeInstruction class
	This creates a change instruction with the given parameters.

	target: This is the sprite the instruction is executed on.
	When: This is the time the instruction occurs at.
	Values: This is a map of the different paraeters and their values.
	Length: This is the amount of time the instructions should take
*/
ChangeInstruction::ChangeInstruction (Sprite* target,int When, std::map<PARAM_MAP>* Values,int Length){
	Target=target;
	Parameters = Values;
	At=When;
	Duration=Length;
	return;
}

/*
perform: This function makes the changes it was set to make
*/
void ChangeInstruction::perform() {
	//Do it!
	Target->changeParameters(Parameters,Duration);
	return;
}

