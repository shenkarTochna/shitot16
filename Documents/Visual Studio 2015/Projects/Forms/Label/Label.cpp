#include "Label.h"



Label::Label(int _width) {
	this->width = _width;
	this->height = 1;
	this->showed = true;

}


void Label::SetValue(string _value) {
	this->value = _value;
}


string Label::GetValue() {
	return this->value;
}

void Label::draw(Graphics g, int i, int j, size_t p) {
	
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	graphics.write(i, j, this->GetValue());
	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}

bool Label::canGetFocus() {
	return false;
}

void Label::mousePressed(int x, int y, DWORD button) {};
void Label::keyDown(int keyCode, char character) {};

