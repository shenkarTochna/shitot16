#pragma once
#include "../Control/Control.h"



class Panel : public Control {

private:
	vector<Control*> controls;

public:

	Panel(int _height, int _width);
	void Show();
	void Hide();
	bool canGetFocus();
	int getWidth();
	int getHeight();
	bool getShowed();
	void addControl(Control& control, int left, int top);
	void draw(Graphics g, int i, int j, size_t p);
	void getAllControls(vector <Control*>* c);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);

};
