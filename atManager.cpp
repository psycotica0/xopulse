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
	std::map<SPRITE_MAP>::iterator targ=SpriteList.find(Target);
	if (targ == SpriteList.end()) {
		//This sprite doesn't exist, just exit
		return;
	}
	Sprite * sTarget=targ->second;
	//Now parse the Parameter list into a map
	std::map<PARAM_MAP> Params = BreakList(Parameters);
	//Then I need to call this with the instructions.
	TempInstruction.insert(std::pair<int,Instruction*>(At,new SetInstruction(sTarget,At,&Params)));
	return;
}

/*
Change: This is the function that is called when a change command is found.

	At: This is the time the action is to be done at
	Target: Sprite name
	Parameters: This is the parameters and their values
	Duration: This is the amount of milliseconds the changes happen in
*/
void AtManager::Change(int At, char* Target, char*Parameters, int Duration){
	//Since changes only make rates of change, two instructions are put in the queue.
	//The second one is the negative of the first, to undo its actions (Stop it without stopping complimentary actions)
	std::map<SPRITE_MAP>::iterator targ=SpriteList.find(Target);
	if (targ == SpriteList.end()) {
		//This sprite doesn't exist, just exit
		return;
	}
	Sprite * sTarget=targ->second;
	//Now parse the Parameter list into a map
	std::map<PARAM_MAP> Params = BreakList(Parameters);
	//Then I need to call this with the instructions.
	TempInstruction.insert(std::pair<int,Instruction*>(At,new ChangeInstruction(sTarget,At,&Params,Duration)));
	return;
}
/*
BreakList: This function takes in a string and breaks it into a map

	Input: This is a string in the form "p1=val1,p2=val2" etc.
*/
std::map<PARAM_MAP> AtManager::BreakList ( char* Input) {
	int tPos=0;
	char Name[20];
	int Value=0;
	bool State=1; //1 for name, 0 for value
	std::map<PARAM_MAP> Results;
	for (int i=0; 1;i++) {

		if (State) {
			//This is a parameter name
			if ((Input[i] >= 48 && Input[i] <= 57) || (Input[i] >=65 && Input [i] <= 90) || (Input [i] >=97 && Input[i]<=122)) {
				//This is a valid character.
				if (tPos < 19) {
					Name[tPos]=Input[i];
					tPos++;
				}
			} else if (Input[i] == '=')  {
				//This is an equal sign
				Name[tPos]='\0';
				tPos=0;
				State=0;
				Value=0;
			}
		} else {
			//This is a value
			if(Input[i] >=48 && Input[i] <=57) {
				//This is an integer
				Value*=10;
				Value+=Input[i]-48;
			} else if (Input[i] == ',' || Input[i]=='\0') {
				//This is the end of a pair
				Results[Name]=Value;
				State=1;
			}
		}
		if (Input[i]=='\0')	break;
	}
	return Results;
}
void AtManager::parseFile(char * Input){
	Sprite * Guy = new Sprite(BreakList(Input));
	SpriteList["Guy"]=Guy;
	DrawList.push_back(Guy);
	Parameters["width"]=100;
	Parameters["height"]=100;
	return;
}
