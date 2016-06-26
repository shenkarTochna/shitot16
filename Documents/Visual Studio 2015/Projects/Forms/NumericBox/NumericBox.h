#pragma once

#include "../Control/Control.h"

class NumericBox : public Control {

private:
	int width;
	int height = 3;
	int min;
	int max;
	int value = 0;


public:
	NumericBox(int _width, int _min, int _max);
	void SetValue(int _value);
	int GetValue();
	int getWidth();
	int getHeight();
	bool canGetFocus();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
};