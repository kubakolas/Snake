#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <sstream>
#include "Item.h"
#include "Global.h"
using namespace sf;
using namespace std;
std::random_device rdx;
std::mt19937 genx(rdx());
std::uniform_int_distribution<> disx(1, 25);
//
std::random_device rdy;
std::mt19937 geny(rdy());
std::uniform_int_distribution<> disy(1, 12);

class Bomb : public Item
{
public:
	bool dol = 1;
	bool gora = 0;
	void bomba(vector<Snake> & vec, Owoc & owoc, int &sizes, int &tekst, Bomb & bom, Bomb & bom2)
	{
		if (bom.x >= X - 2 || bom.y >= Y - 2)
		{
			bom.gora = 1;
			bom.dol = 0;
		}
		if (bom.x <= 0 || bom.y <= 0)
		{
			bom.gora = 0;
			bom.dol = 1;
		}
		if (bom2.x <= 1 || bom2.y >= Y - 2)
		{
			bom2.gora = 1;
			bom2.dol = 0;
		}
		if (bom2.x >= X - 2 || bom2.y <= 0)
		{
			bom2.gora = 0;
			bom2.dol = 1;
		}
		if ((vec[0].x == x) && (vec[0].y == y) || (vec[0].x == bom.x) && (vec[0].y == bom.y) || (vec[0].x == bom2.x) && (vec[0].y == bom2.y))
		{


			sizes = 2;
			tekst = 0;
			do
			{
				x = disx(genx);
				y = disy(geny);
			} while (x != owoc.x && y != owoc.y);
			bom.x = -2;
			bom.y = -1;
			bom.dol = 1;
			bom.gora = 0;
			bom2.x = 31;
			bom2.y = -1;
			bom2.dol = 1;
			bom2.gora = 0;

		}
	}

};