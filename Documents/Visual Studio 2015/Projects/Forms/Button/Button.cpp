#include "Button.h"


Button::Button(int _width) {
	this->width = _width;
	this->height = 1;
	this->border = BorderType::Single;
	this->showed = true;
	this->value = "Submit";


}

void Button::SetValue(string _value) {
	this->value = _value;
}

string Button::GetValue() {
	return this->value;
}

bool Button::canGetFocus() {
	return false;
}

void Button::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	drawBackground();
	graphics.write(i, j, this->GetValue());


}

void Button::keyDown(int keyCode, char character) {

	this->graphics.clearScreen();



}

void Button::mousePressed(int x, int y, DWORD button) {


		listener->MousePressed(*this, x, y, true);


}


void Button :: AddListener(MouseListener &_listener) {
	this->listener = &_listener;
}

