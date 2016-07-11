#pragma once
#include "RadioBox.h"


RadioBox::RadioBox(int _height, int _width, vector<string> _options) {

	this->height = _height;
	this->width = _width;
	this->options = _options;
	this->checked = { 0,0 };

}


bool RadioBox::canGetFocus() {
	return true;
}


int RadioBox::getWidth() {
	return this->width;
}

void RadioBox::draw(Graphics g, int i, int j, size_t p) {

	for (int k = 0; k < this->options.size(); k++) {
		if (this->checked[k] == 0) {
			graphics.write(i, j + k, "[ ]");
			graphics.write(i + 7, j + k, this->options[k]);
		}

		if (this->checked[k] == 1) {
			graphics.write(i, j + k, "[X]");
			graphics.write(i + 7, j + k, this->options[k]);
		}

	}

}

void  RadioBox::keyDown(int keyCode, char character) {

	this->setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		moveTo(this->getLeft() +1, this->getTop() + i);
		int c = 0;
		c = getchar();
		do {
			if (c == VK_TAB) {
				break;
			}

				this->checked[i] = 1;
				putchar('X');
				for (int k = 0; k < this->options.size(); k++)
				{
					if (i != k) {
						this->checked[i] = 0;
						moveTo(this->getLeft() + 1, this->getTop() + k);
						putchar(' ');
					}
					break;
				}

				break;
		} while (c != VK_TAB);

	}

}


vector<size_t> RadioBox::GetSelectedIndices() {

	return this->checked;

}


void RadioBox::SelectIndex(size_t index) {

	this->checked[index] = 1;
}

void RadioBox::DeselectIndex(size_t index) {

	this->checked[index] = 0;
}