#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <cairo.h>
#include <map>
#include <string>
#include "global.h"

/*
Sprite: This class is meant to represent the sprites on the screen.
*/
class Sprite {
	protected:
		//This is a map of all parameters and their values
		std::map<PARAM_MAP> Parameters;
		//This is a map of the rates of change of each parameter
		//From a performance standpoint, it's probably better to remove a rate from the map rather than set its value to 0 
		std::map<RATE_MAP> Rates;
		//This function takes two maps, and changes all values in Target to match those in Source. This involves changing existing values and inserting new ones.
		//EraseZero sets whether or not setting an item to 0 removes it from the list or not.
		void mergeMaps (std::map<PARAM_MAP>* Target, std::map<PARAM_MAP>* Source, bool EraseZero=0);
		//This variable keeps track of all changes, so that they are stopped
		std::multimap<int,std::map<PARAM_MAP> > ChangeStops;
		//This variable keeps track of the last time the sprite was drawn
		int NOW;
	public:
		//This function will have the sprite draw itself on the screen
		void repaint(int,cairo_t *,std::map<PARAM_MAP> ); 
		//This function will set the parameters of the sprite
		void setParameters(std::map<PARAM_MAP>*);
		//This function will set the rates of change of the sprite
		void changeParameters(std::map<PARAM_MAP>*,int );
		//This is a constructor that sets the given parameters
		Sprite (std::map<PARAM_MAP>);
};

#endif
