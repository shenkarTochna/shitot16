#pragma once
#include "CheckList.h"


CheckList::CheckList(int _height, int _width, vector<string> _options) {

	this->height = _height;
	this->width = _width;
	this->options = _options;
	this->checked = { 0,0,0 };
	this->showed = true;

}


bool CheckList::canGetFocus() {
	return true;
}


void CheckList::draw(Graphics g, int i, int j, size_t p) {
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

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

void  CheckList::keyDown(int keyCode, char character) {

	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		graphics.moveTo(this->getLeft() + 1, this->getTop() + i);


		int c = 0;
		c = getchar();


		do {
			if (c == VK_TAB) {
				break;
			}
			switch (this->checked[i]) {
			case 1:
				this->checked[i] = 0;
				putchar(' ');
				break;

			case 0:
				this->checked[i] = 1;
				putchar('X');
				break;

			}

			break;
		} while (c != VK_TAB);

	}

}

void CheckList::mousePressed(int x, int y, DWORD button) {
	
	for (int i = 0; i < this->getHeight(); i++)
	{
		if (x == (this ->getLeft()+1) && y == (this->getTop()+i)) {
			
			graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
			switch (this->checked[i]) {
			case 1:
				this->checked[i] = 0;
				putchar(' ');
				break;

			case 0:
				this->checked[i] = 1;
				putchar('X');
				break;

			}
			break;
		}
	}
}


vector<size_t> CheckList::GetSelectedIndices() {

	return this->checked;

}


void CheckList::SelectIndex(size_t index) {

	this->checked[index] = 1;
}

void CheckList::DeselectIndex(size_t index) {

	this->checked[index] = 0;
}

