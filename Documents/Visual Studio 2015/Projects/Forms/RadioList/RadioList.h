#pragma once
#include "../Control/Control.h"
#include "../CheckList/CheckList.h"
class RadioList : public Control {

private:
	vector<string> options;
	size_t checked=0;

public:
	RadioList(int _height, int _width, vector<string> _options);
	void Show();
	void Hide();
	bool canGetFocus();
	int getWidth();
	int getHeight();
	bool getShowed();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	//void SelectIndex(size_t index);
	//void DeselectIndex(size_t index);


};