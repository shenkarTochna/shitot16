#pragma once
#include <string> 
#include "NumericBox.h"


NumericBox::NumericBox(int _width, int _min, int _max) {
	this->width = _width;
	this->min = _min;
	this->max = _max;
}

void NumericBox::SetValue(int _value) {
	this->value = _value;
}

int NumericBox::GetValue() {
	return this->value;
}

int NumericBox::getWidth() {
	return this->width;
}

bool NumericBox::canGetFocus() {
	return true;
}

void NumericBox::draw(Graphics g, int i, int j, size_t p) {

	g.write(i, j + 1, "[-]");
	g.write(i + 3, j, "\xC9");
	for (int i = 0; i < this->width; i++) {
		g.write("\xCD");
	}
	g.write("\xBB\n");
	g.write(i + 3, j + 1, "\xBA");
	g.write(i + this->width + 4, j + 1, "\xBA");
	g.write(i + 3, j + 2, "\xC8");
	for (int i = 0; i < this->width; i++) {
		g.write("\xCD");
	}
	g.write("\xBC");

	std::string val = std::to_string(this->value);
	g.write(i + 4, j + 1, val);
	g.write(i + this->width + 5, j + 1, "[+]");

}

void NumericBox::keyDown(int keyCode, char character) {

	this->setCursorVisibility(true);

	for (int i = 0; i < 2; i++)
	{
		if (i == 0) {
			moveTo(this->getLeft() + 1, this->getTop() + 1);
		}
		if (i == 1) {
			moveTo(this->getLeft() + this->getWidth() + 6, this->getTop() + 1);
		}
		int c;
		do {
			c = getchar();
			if (i == 0) {
				this->SetValue(this->value - 1);
				write(this->getLeft() + 4, this->getTop() + 1, std::to_string(this->GetValue()));

			}
			if (i == 1) {
				this->SetValue(this->value + 1);
				write(this->getLeft() + 4, this->getTop() + 1, std::to_string(this->GetValue()));

			}
		} while (c != VK_TAB);
	}

}

void NumericBox::mousePressed(int x, int y, DWORD button) {



	this->setCursorVisibility(true);
	moveTo(this->getLeft() + 1, this->getTop() + 1);

	const int n = this->width;
	int c;

	do {
		c = getchar();
		putchar(c);
	} while (c != '.');
}
