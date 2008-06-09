#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <cairo.h>
#include <map>

/*
Sprite: This class is meant to represent the sprites on the screen.
*/
class Sprite {
	protected:
		//This is a map of all parameters and their values
		std::map<char *,int> Parameters;
		//This is a map of the rates of change of each parameter
		//From a performace standpoint, it's probably better to remove a rate from the map rather than set its value to 0 
		std::map<char *,int> Rates;
		//This function takes two maps, and changes all values in Target to match those in Source. This involves changing existing values and inserting new ones.
		//EraseZero sets whether or not setting an item to 0 removes it from the list or not.
		void mergeMaps (std::map<char*,int>* Target, std::map<char*, int>* Source, bool EraseZero=0);
	public:
		//This function will have the sprite draw itself on the screen
		void repaint(int,cairo_t *); 
		//This function will set the parameters of the sprite
		void setParameters(std::map<char *,int>*);
		//This function will set the rates of change of the sprite
		void setRates(std::map<char *,int>*);
		//This is a constructor that sets the given parameters
		Sprite (std::map<char*, int>*);
};

#endif
