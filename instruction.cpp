#include "instruction.h"

int Instruction::when() {
	return At;
}

SetInstruction::SetInstruction (Sprite* target,int When, std::map<char *, int>* Values){
	Target=target;
	Parameters = Values;
	At=When;
	return;
}

void SetInstruction::perform () {
	//Do it!
	Target->setParameters(Parameters);
	return;
}
