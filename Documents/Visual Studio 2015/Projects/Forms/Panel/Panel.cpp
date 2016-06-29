#include <iostream>
#include <typeinfo>
#include "Panel.h"


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

int Panel::getHeight() {
	return this->height;
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

	for (int k = 0; k < this->controls.size()-1 ; k++) {
		if ((controls[k]->getLeft() + controls[k]->getWidth()) > controls[k + 1]->getLeft() ||
			(controls[k]->getTop() + controls[k]->getHeight()) > controls[k + 1]->getTop()) {
			controls[k + 1]->Hide();

		}
	}

	for (int k = 0; k < this->controls.size(); k++) {

		if (controls[k]->getShowed() == true) {
			controls[k]->draw(g, controls[k]->getLeft(), controls[k]->getTop(), 0);
		}
	}
}

void Panel::getAllControls(vector <Control*>* c) { *c = this->controls; }



void Panel::mousePressed(int x, int y, DWORD button) {

	for (int k = 0; k < this->controls.size(); k++) {
		
		if (isInside(x, y, this->controls[k]->getLeft(), this->controls[k]->getTop(), this->controls[k]->getWidth(), this->controls[k]->getHeight()))
		{
			setFocus(*this->controls[k]);
			this->controls[k]->mousePressed(x, y, button);

			break;
		}
	}

};
void Panel::keyDown(int keyCode, char character) {};

void Panel::Show() {
	this->showed = true;
}

void Panel::Hide() {
	this->showed = true;
}


bool Panel::getShowed() {
	return this->showed;
}