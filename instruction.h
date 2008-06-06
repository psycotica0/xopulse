#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "sprite.h"

class Instruction {
	public:
		Instruction(Sprite);
		void perform();
};

#endif
