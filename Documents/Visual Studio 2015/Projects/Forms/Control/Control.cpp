#include "Control.h"
#include <iostream>
#include <vector>
#define VNAME(x) #x

using namespace std;

Control* Control::focus = 0;

void Control::Show() {
	cout << "show" << endl;
}

void Control::Hide() {
	cout << "hide";
}


Control* Control::getFocus() {

	return focus;
}


void Control::setFocus(Control &control) {
	control.setCursorVisibility(true);
	focus = &control;

	control.setForeground(Color::Red);



}

void Control::setLeft(int _left) {
	this->left = _left;
}

void Control::setTop(int _top) {
	this->top = _top;
}

int Control::getLeft() {
	return this->left;
}

int Control::getTop() {
	return this->top;
}


void Control::setWidth(int _width) {
	this->width = _width;
}




void Control::setValue(int value) {}
void Control::isFocused() {}

void Control::getAllControls(vector <Control*>* c) {};

int Control::getWidth() {
	return this->width;
}

int Control::getHeight() {
	return this->height;
}

bool Control::getShowed() {
	return this->showed;
}

BorderType Control::getBorder() {
	return this->border;
}

void Control::drawBorder(BorderType border) {
	int i = this->getLeft()-1;
	int j = this->getTop()-1;

	switch (border) {

	case BorderType::Double:

		write(i, j, "\xC9");
		for (int k = 0; k < this->width; k++) {
			write("\xCD");
		}
		write("\xBB\n");
		for (int k = 1; k < this->height+1; k++) {
			write(i, j + k, "\xBA");
			write(i + this->width + 1, j + k, "\xBA\n");
		}
		write(i, j + this->height+1, "\xC8");
		for (int i = 0; i < this->width; i++) {
			write("\xCD");
		}
		write("\xBC");
		break;

	case BorderType::None:

		break;

	case BorderType::Single:

		write(i, j, "\xDA");
		for (int k = 0; k < this->width; k++) {
			write("\xC4");
		}
		write("\xBF\n");
		for (int k = 1; k < this->height+1; k++) {
			write(i, j + k, "\xB3");
			write(i + this->width + 1, j + k, "\xB3\n");
		}
		write(i, j + this->height+1, "\xC0");
		for (int i = 0; i < this->width; i++) {
			write("\xC4");
		}
		write("\xD9");
		break;
	}
}

void Control::SetBorder(BorderType _border) {

	this->border = _border;
	}

