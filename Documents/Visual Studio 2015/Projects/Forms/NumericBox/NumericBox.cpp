#pragma once
#include <string> 
#include "NumericBox.h"


NumericBox::NumericBox(int _width, int _min, int _max) {
	this->width = _width;
	this->height = 3;
	this->min = _min;
	this->max = _max;
	this->showed = true;
}

void NumericBox::SetValue(int _value) {
	this->value = _value;
}

int NumericBox::GetValue() {
	return this->value;
}

bool NumericBox::canGetFocus() {
	return true;
}

void NumericBox::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);


	graphics.write(i, j + 1, "[-]");
	graphics.write(i + 3, j, "\xC9");
	for (int k = 0; k < this->getWidth() -8; k++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBB\n");
	graphics.write(i + 3, j + 1, "\xBA");
	graphics.write(i + this->getWidth()- 4, j + 1, "\xBA");
	graphics.write(i + 3, j + 2, "\xC8");
	for (int k = 0; k < this->getWidth() -8; k++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBC");

	std::string val = std::to_string(this->value);
	graphics.write(i+this->getWidth() /2, j + 1, val);
	graphics.write(i + this->getWidth() -3, j + 1, "[+]");


	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);

}

void NumericBox::keyDown(int keyCode, char character) {

	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < 2; i++)
	{
		if (i == 0) {
			graphics.moveTo(this->getLeft() + 1, this->getTop() + 1);
		}
		if (i == 1) {
			graphics.moveTo(this->getLeft() + this->getWidth() + 6, this->getTop() + 1);
		}
		int c;
		do {
			c = getchar();
			if (i == 0) {
				this->SetValue(this->value - 1);
				graphics.write(this->getLeft() + 4, this->getTop() + 1, std::to_string(this->GetValue()));

			}
			if (i == 1) {
				this->SetValue(this->value + 1);
				graphics.write(this->getLeft() + 4, this->getTop() + 1, std::to_string(this->GetValue()));

			}
		} while (c != VK_TAB);
	}

}

void NumericBox::mousePressed(int x, int y, DWORD button) {

	this->graphics.setCursorVisibility(true);
	graphics.moveTo(x,y);

	if (x == this->getLeft() + 1) {
		if (this->value > this->min)
		{
			this->SetValue(this->value - 1);
		}
	}

	if (x == (this->getLeft()+this->getWidth()-2)) {

		if (this->value < this->max)
		{
			this->SetValue(this->value + 1);
		}
	}

}
