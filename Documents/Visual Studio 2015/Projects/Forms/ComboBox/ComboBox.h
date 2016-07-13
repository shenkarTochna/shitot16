#pragma once

#include "../Control/Control.h"


class ComboBox : public Control {

private:

	vector<string> options;
	size_t selected;
	bool isOpened = false;




public:
	ComboBox(int width, vector<string> options);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	bool canGetFocus();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
};

