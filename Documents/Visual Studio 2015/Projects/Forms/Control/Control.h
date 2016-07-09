#pragma once
#include <vector>
#include "../Graphics/Graphics.h"


enum class BorderType { Single, Double, None };
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };


class Control : public Graphics {

protected:
	int left;
	int top;
	int width;
	int height;
	bool showed = true;
	BorderType border = BorderType::None;
	ForegroundColor foreground = ForegroundColor::Yellow;
	static Control* focus;

public:
	virtual void Show() =0;
	virtual void Hide() =0;
	virtual void draw(Graphics g, int i, int j, size_t p) = 0;
	virtual void getAllControls(vector <Control*>* c);
	static Control* getFocus();
	static void setFocus(Control &control);
	void setLeft(int _left);
	void setTop(int _top);
	int getLeft();
	int getTop();
	virtual void setWidth(int _width);
	int getWidth();
	int getHeight();
	bool getShowed();
	BorderType getBorder();
	virtual void isFocused();
	virtual void mousePressed(int x, int y, DWORD button)=0;
	virtual void keyDown(int keyCode, char character)=0;
	virtual bool canGetFocus() = 0;
	virtual void setValue(int value);
	void SetBorder(BorderType _border);
	void drawBorder(BorderType _border);
	void SetForeground(Color color);
	void SetBackground(Color color);



};
