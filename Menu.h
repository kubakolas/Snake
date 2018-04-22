#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <sstream>
#include "Item.h"
using namespace sf;
using namespace std;
class Menu
{
public:
	int wybor = 0;
	bool up2 = 0;
	bool down2 = 0;
	void menu(Font& font, Text & graj, Text & exits)
	{

		if (up2 == 1 && graj.getFillColor() == Color::Blue)
		{
			graj.setFillColor(Color::White);
			exits.setFillColor(Color::Blue);
			up2 = 0;
		}
		if (down2 == 1 && graj.getFillColor() == Color::Blue)
		{
			graj.setFillColor(Color::White);
			exits.setFillColor(Color::Blue);
			down2 = 0;
		}
		if (up2 == 1 && graj.getFillColor() == Color::White)
		{
			graj.setFillColor(Color::Blue);
			exits.setFillColor(Color::White);
			up2 = 0;
		}
		if (down2 == 1 && graj.getFillColor() == Color::Blue)
		{
			exits.setFillColor(Color::Blue);
			graj.setFillColor(Color::White);
			down2 = 0;
		}
		if (down2 == 1 && exits.getFillColor() == Color::Blue)
		{
			graj.setFillColor(Color::Blue);
			exits.setFillColor(Color::White);
			down2 = 0;
		}
		if (graj.getFillColor() == Color::Blue && (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return)))
		{
			wybor = 1;
		}
		if (exits.getFillColor() == Color::Blue && (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return)))
		{
			wybor = 2;
		}
	}
};