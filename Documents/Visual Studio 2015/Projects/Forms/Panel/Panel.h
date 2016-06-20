#pragma once
#include "../Control/Control.h"



class Panel : public Control {

private:
	int height;
	int width;
	vector<Control*> controls;

public:

	Panel(int _height, int _width);
	bool canGetFocus();
	int getWidth();
	void addControl(Control& control, int left, int top);
	void draw(Graphics g, int i, int j, size_t p);
	void getAllControls(vector <Control*>* c);
	void mousePressed(int x, int y, DWORD button);
	virtual void keyDown(int keyCode, char character);

};
