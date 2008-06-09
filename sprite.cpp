#include "sprite.h"

/*
repaint: This function calculates its current position and draws itself.

	time: This is the number of milliseconds since the movie started
		It should use this to calculate it's position
	buffer: This is the buffer to draw the sprite in.
*/
void Sprite::repaint(int time, cairo_t * buffer) {
	return;
}

/*
setParameters: This function is called when an instruction wants to set parameters in a sprite

	Values: This is a map of parameters names and values to set
*/
void Sprite::setParameters(std::map<char *,int>* Values){ 
	mergeMaps(&Parameters, Values);
	return;
}

/*
setRates: This function changes the rates of change of parameters.

	Values: This is a map of parameters names and values to set
*/
void Sprite::setRates(std::map<char *,int>* Values){ 
	mergeMaps(&Rates, Values);
	return;
}

/*
Sprite: This is a constructor that makes a sprite with initial parameters

	Values: This is a map of parameters to set
*/
Sprite::Sprite (std::map<char*,int>* Values) {
	Parameters=*Values;
	return;
}

/*
mergeMaps: This function changes all elements in the first map to match the values given in the second
	It doesn't copy the map, it just syncs the first with the second.

	Target: This is a pointer to the map to change
	Source: This is a pointer to a map to get the values from
	EraseZero: This is an optional parameter.
		If EraseZero is 1, then a parameter is removes from Target when the value given in Source is 0
		If it's 0, then the value of 0 is put in Target, and nothing is removed
		0 is the default.
*/
void Sprite::mergeMaps(std::map<char *,int>* Target, std::map<char *,int>* Source,bool EraseZero) {
	for (std::map<char*,int>::iterator i=Source->begin(); i!= Source->end(); i++){
		if (EraseZero) {
			if (i-> second == 0) {
				Target->erase(i->first);
				continue;
			}
		}
		(*Target)[i->first]=i->second;
	}
	return;
}
