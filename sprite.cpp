#include "sprite.h"

void Sprite::repaint(int time, cairo_t * buffer) {
	return;
}

void Sprite::setParameters(std::map<char *,int>* Values){ 
	mergeMaps(&Parameters, Values);
	return;
}

void Sprite::setRates(std::map<char *,int>* Values){ 
	mergeMaps(&Rates, Values);
	return;
}

Sprite::Sprite (std::map<char*,int>* Values) {
	Parameters=*Values;
	return;
}

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
