#include "Control.h"
#include <iostream>
#include <vector>
#define VNAME(x) #x

using namespace std;

Control* Control::focus = 0;

enum class BorderType { Single, Double, None };



void Control::Show() {
	cout << "show" << endl;
}

void Control::Hide() {
	cout << "hide";
}

void Control::SetBorder(Color border) {
	cout << "setborder" << endl;
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



