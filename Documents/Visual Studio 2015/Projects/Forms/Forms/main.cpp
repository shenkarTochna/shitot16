#include <iostream>
#include "../Control/Control.h"
#include "../Graphics/Graphics.h"
#include "../EventEngine/EventEngine.h"
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../CheckList/CheckList.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../RadioList/RadioList.h"
#include "../TextBox/TextBox.h"
#include "../ComboBox/ComboBox.h"
#include "../MessageBox/MessageBox.h"

using namespace std;


struct MyListener : public MouseListener
{
private:
	Control &_c;

public:

	MyListener(Control &c) : _c(c) { }
	
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.Show();
	}

};


void main() {
	Label lName(20);
	lName.SetValue("Name: ");

	Label lAddress(20);
	lAddress.SetValue("Address:");
	Label lCountry(20);
	lCountry.SetValue("Counrty:");
	Label lSex(20);
	lSex.SetValue("Sex:");
	Label lInterests(20);
	lInterests.SetValue("Interests:");
	Label lAge(20);
	lAge.SetValue("Age:");
	TextBox tName(20);
	TextBox tAddress(25);
	tAddress.SetValue("221B Baker Street, London");
	Button bSubmit(10 );
	bSubmit.SetValue("Submit");
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	NumericBox nAge(15, 18, 120);
	nAge.SetValue(23);
	RadioList rSex(2, 15, { "Male", "Female" });
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.SetSelectedIndex(1);
	Messagebox results(30, 10);
	results.SetTitle("WELCOME !");
	results.SetText("Hi, " + tName.GetValue() + "and welcome to our form system.");
	
	bSubmit.AddListener(MyListener::MyListener(results));
	bSubmit.SetBackground(BackgroundColor::Green);

	cCountry.SetForeground(ForegroundColor::Green);
	clInterests.SetBorder(BorderType::Single);
	cCountry.SetBorder(BorderType::Double);
	tAddress.SetBorder(BorderType::Double);
	rSex.SetBorder(BorderType::Single);

	Panel main(27, 55);
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 20);
	main.addControl(bSubmit, 25, 25);
	main.addControl(results, 5, 5);

	Control::setFocus(tName);
	EventEngine engine;
	engine.run(main);

}


