#pragma once
#include "RadioList.h"


RadioList::RadioList(int _height, int _width, vector<string> _options) {

	this->height = _height;
	this->width = _width;
	this->options = _options;
	this->checked = 0 ;

}


bool RadioList::canGetFocus() {
	return true;
}


int RadioList::getWidth() {
	return this->width;
}


int RadioList::getHeight() {
	return this->height;
}

void RadioList::draw(Graphics g, int i, int j, size_t p) {

	for (int k = 0; k < this->options.size(); k++) {


		if (this->checked == k) {
			g.write(i, j + k, "[X]");
			g.write(i + 7, j + k, this->options[k]);
		}
		else {
			g.write(i, j + k, "[ ]");
			g.write(i + 7, j + k, this->options[k]);
		}

	}

}

void  RadioList::keyDown(int keyCode, char character) {

	this->setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		moveTo(this->getLeft() + 1, this->getTop() + i);
		int c = 0;
		c = getchar();
		do {
			if (c == VK_TAB) {
				break;
			}

			this->checked = 1;
			putchar('X');
			for (int k = 0; k < this->options.size(); k++)
			{
				if (i != k) {
					this->checked = 0;
					moveTo(this->getLeft() + 1, this->getTop() + k);
					putchar(' ');
				}
				break;
			}

			break;
		} while (c != VK_TAB);

	}

}

void RadioList::mousePressed(int x, int y, DWORD button) {

	for (int i = 0; i < this->getHeight(); i++)
	{
		if (x == (this->getLeft() + 1) && y == (this->getTop() + i)) {

			moveTo(this->getLeft() + 1, this->getTop() + i);
			if (this->checked != i) {
				moveTo(this->getLeft() + 1, this->getTop() + this->checked);
				putchar(' ');
				this->checked = i;
				moveTo(this->getLeft() + 1, this->getTop() + i);
				putchar('X');
				
			}

			break;
		}
	}
};


size_t  RadioList::GetSelectedIndex() {
	return this->checked;
};

void  RadioList::SetSelectedIndex(size_t index) {
	this->checked = index;
};


//void RadioList::SelectIndex(size_t index) {

	//this->checked[index] = 1;
//}

//void RadioList::DeselectIndex(size_t index) {

	//this->checked[index] = 0;
//}

void RadioList::Show() {
	this->showed = true;
}

void RadioList::Hide() {
	this->showed = false;
}


bool RadioList::getShowed() {
	return this->showed;
}