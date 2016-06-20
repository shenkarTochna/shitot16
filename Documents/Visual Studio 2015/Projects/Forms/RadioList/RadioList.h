#pragma once
#include "../Control/Control.h"

class RadioList : public Control {

private:
	int height;
	int width;
	vector<string> options;
	vector<size_t> checked;

public:
	RadioList(int _height, int _width, vector<string> _options);
	bool canGetFocus();
	int getWidth();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);


};