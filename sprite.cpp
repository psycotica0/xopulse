#include "sprite.h"

/*
repaint: This function calculates its current position and draws itself.

	time: This is the number of milliseconds since the movie started
		It should use this to calculate it's position
	buffer: This is the buffer to draw the sprite in.
	With: This is a parameter map passed to the sprite to tell it the parameters it needs to use to augment it's own with
		These are meant to be passed down from the parent sprite so that the child sprites can stay synced up.
*/
void Sprite::repaint(int time, cairo_t * buffer, std::map<PARAM_MAP> With) {
	NOW=time;
	//First, I need to check if any change stop requests are due.
	//Then I need to make an effective parameter set that is a mix of mine and With.
	//Then draw with those parameters.
	//Then draw children, passing the effective parameters to them too.
	return;
}

/*
setParameters: This function is called when an instruction wants to set parameters in a sprite

	Values: This is a map of parameters names and values to set
*/
void Sprite::setParameters(std::map<PARAM_MAP>* Values){ 
	mergeMaps(&Parameters, Values);
	return;
}

/*
changeParameters: This function changes the rates of change of parameters.

	Values: This is a map of parameters names and values to change
	Duration: This is the time it should take to do so
*/
void Sprite::changeParameters(std::map<PARAM_MAP>* Values, int Duration){ 
	std::map<PARAM_MAP> Opposite;
	for (std::map<PARAM_MAP>::iterator i=Values->begin(); i!=Values->end(); i++){
		//Apparently, rotation is given in relative, but everything else is absolute.
		if(i->first == "angle" ) {
			//This is relative
			Rates[i->first]+=(i->second)/Duration;
			Opposite[i->first]=-i->second/Duration;
		} else {
			//This is absolute
			Rates[i->first]+=(i->second-Parameters[i->first])/Duration;
			Opposite[i->first]=(Parameters[i->first]-i->second)/Duration;
		}
	}
	//This adds the calculated values to the reverse matrix, so that the rate can be removed at the end of the duration
	ChangeStops.insert(std::pair<int,std::map<PARAM_MAP> >(Duration+NOW,Opposite));
	return;
}

/*
Sprite: This is a constructor that makes a sprite with initial parameters

	Values: This is a map of parameters to set
*/
Sprite::Sprite (std::map<PARAM_MAP> Values) {
	Parameters=Values;
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
void Sprite::mergeMaps(std::map<PARAM_MAP>* Target, std::map<PARAM_MAP>* Source,bool EraseZero) {
	for (std::map<PARAM_MAP>::iterator i=Source->begin(); i!= Source->end(); i++){
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
