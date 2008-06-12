#include "manager.h"

/*
render: This is the loop that runs and calculates positions.
	It does so by calling things like repaint.
*/
void Manager:: render () {
	for (std::list<Sprite*>::iterator i=DrawList.begin(); i != DrawList.end(); i++ ){
		//For testing purposes, just draw the thing
		(*i)->repaint(0,Buffer,Parameters);
	}
	return;
}

/*
repaint: This is the function that calculates the current posision of each sprite and draw them
	Well, actually it just goes through the list of drawn sprites and tells them to draw themselves.

	time: This is the integer for milliseconds to calculate the current position with.
*/
void Manager:: repaint (int time) {
	return;
}
