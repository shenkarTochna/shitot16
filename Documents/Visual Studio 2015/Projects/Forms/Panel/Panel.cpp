#include "Panel.h"
#include <iostream>

using namespace std;


Panel::Panel(int _height, int _width) {
	this->height = _height; this->width = _width;

}

bool Panel::canGetFocus() {
	return false;
}


int Panel::getWidth() {
	return this->width;
}

void Panel::addControl(Control& control, int left, int top) {
	this->controls.push_back(&control);
	control.setLeft(left);
	control.setTop(top);


}

void Panel::draw(Graphics g, int i, int j, size_t p) {

	g.write(i, j, "\xC9");
	for (int k = 0; k < this->width; k++) {
		g.write("\xCD");
	}
	g.write("\xBB\n");
	for (int k = 1; k < this->height; k++) {
		g.write(i, j + k, "\xBA");
		g.write(i + this->width + 1, j + k, "\xBA\n");
	}
	g.write(i, j + this->height, "\xC8");
	for (int i = 0; i < this->width; i++) {
		g.write("\xCD");
	}
	g.write("\xBC");


	for (int k = 0; k < this->controls.size(); k++) {
		controls[k]->draw(g, controls[k]->getLeft(), controls[k]->getTop(), 0);
	}
}

void Panel::getAllControls(vector <Control*>* c) { *c = this->controls; }


void Panel::mousePressed(int x, int y, DWORD button) {


	for (int i = 0; i< this->controls.size(); i++) {
		if (this->controls[i]->canGetFocus() == true) {
			//	if (x > this->controls[i]->getLeft() && x < this->controls[i]->getLeft() + this->controls[i]->getWidth());

			//	{
			//setFocus(*controls[i]);
			//	setCursorVisibility(true);
			//	break;
			//}

			if (x == 25 && y == 20) {
				controls[10]->setValue(26);
			}
		}
	}
}

void Panel::keyDown(int keyCode, char character) {};