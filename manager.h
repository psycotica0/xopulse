#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "instruction.h"
#include "sprite.h"
#include <cairo.h>
#include <queue>
#include <map>
#include <list>

class Manager {
	protected:
		//This contains the chronologically sorted list of actions to perform
		std::queue<Instruction*> InstructList;
		//This holds a list of all Sprites by name
		std::map<char *, Sprite*> SpriteList;
		//This holds a list of all sprites that are currently being drawn
		std::list <Sprite *> DrawList;
		//This is the cairo buffer to draw the sprites at.
		cairo_t * Buffer;
	public:
		//This function starts the scene generation loop. It should call repaint every time it wants to draw the scene on the screen.
		void render();
		//This function uses the passed in time (In milliseconds since the movie started) to draw the sprites.
		void repaint(int);
};

#endif
