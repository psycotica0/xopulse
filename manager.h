#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "instruction.h"
#include <cairo.h>

class Manager {
	public:
		Manager(Instruction *,cairo_t *);
		void render();
		void repaint(int);
};

#endif
