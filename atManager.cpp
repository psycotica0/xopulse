#include "atManager.h"

void AtManager::Set(int At, char* Target, char* Parameters){
	std::map<char*,Sprite*>::iterator targ=SpriteList.find(Target);
	if (targ == SpriteList.end()) {
		//This sprite doesn't exist, just exit
		return;
	}
	Sprite * sTarget=targ->second;
	//In here I need to parse the parameter list into a map

	//Then I need to call this with the instructions.
	//TempInstruction[At]=new SetInstruction();
	return;
}

void AtManager::Change(int At, char* Sprite, char*Parameters, int Duration){
	return;
}

void AtManager::parseFile(char * Input){
	return;
}
