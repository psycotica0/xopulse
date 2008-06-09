#include "atManager.h"

/*
Set: This function is called when a set instruction is found.
	It is in charge of making the instruction and adding it to the map of instruction objects

	At: This is the integer representing when the instruction occurs.
		It's in milliseconds since the beginning of the movie.
	Target: This is a string representing the name of the Sprite.
	Parameters: This is the string from the instruction that is the parameter list
		This function is in charge of making a map from it.
*/
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
