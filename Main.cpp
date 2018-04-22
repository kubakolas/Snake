#include "Item.h"
#include "Bomb.h"
#include "Menu.h"
#include "Sterowanie.h"
void ruch(vector<Snake> & vec, Sterowanie & ster, int &sizes, int &tekst, Owoc & owoc, Bomb & bomb, Bomb & bomb2, Bomb & bomb3)
{
	for (int i = sizes; i > 0; --i)
	{
		vec[i].x = vec[i-1].x;
		vec[i].y = vec[i-1].y;
	}
	//kierowanie
	if (ster.up == 1)
	{
		vec[0].y -= 1;
		
	}
	if (ster.down == 1)
	{
		vec[0].y += 1;
		
	}
	if (ster.lefts == 1)
	{
		vec[0].x -= 1;
		
	}
	if (ster.rights == 1)
	{
		vec[0].x += 1;
		
	}
	//zjedzenie
	if ((vec[0].x == owoc.x)  && (vec[0].y == owoc.y) )
	{
		tekst++;
		sizes++;
		owoc.x = disx(genx);
		owoc.y = disy(geny);
	}
	//bomba

	bomb.bomba(vec, owoc, sizes, tekst, bomb2, bomb3);
	//zderzenie ze scianami

	if (vec[0].x == X)
	{
		ster.down = 1;
		ster.lefts = 0;
		ster.rights = 0;
		ster.up = 0;
		vec[0].x = 0;
		vec[0].y = 0;
		sizes = 2;
		tekst = 0;
		bomb2.x = -2;
		bomb2.y = -1;
		bomb3.x = 31;
		bomb3.y = -1;
	}
	if (vec[0].x < 0)
	{
		ster.down = 1;
		ster.lefts = 0;
		ster.rights = 0;
		ster.up = 0;
		vec[0].x = 0;
		vec[0].y = 0;
		sizes = 2;
		tekst = 0;
		bomb2.x = -2;
		bomb2.y = -1;
		bomb3.x = 31;
		bomb3.y = -1;
	}
	if (vec[0].y == Y)
	{
		ster.down = 1;
		ster.lefts = 0;
		ster.rights = 0;
		ster.up = 0;
		vec[0].x = 0;
		vec[0].y = 0;
		sizes = 2;
		tekst = 0;
		bomb2.x = -2;
		bomb2.y = -1;
		bomb3.x = 31;
		bomb3.y = -1;
	}
	if (vec[0].y < 0)
	{
		ster.down = 1;
		ster.lefts = 0;
		ster.rights = 0;
		ster.up = 0;
		vec[0].x = 0;
		vec[0].y = 0;
		sizes = 2;
		tekst = 0;
		bomb2.x = -2;
		bomb2.y = -1;
		bomb3.x = 31;
		bomb3.y = -1;
	}
	
	//game over
	for (int i = 1; i<sizes; i++)
		if (vec[0].x == vec[i].x && vec[0].y == vec[i].y)
		{
			sizes = 2;
			tekst = 0;
			bomb2.x = -2;
			bomb2.y = -1;
			bomb3.x = 31;
			bomb3.y = -1;

		}
}

int main()
{
	vector<Snake> vec(200);
	int sizes = 2;
	int tekst = 0;

	Sterowanie ster;
	//menu
	Menu menu;
	Font font;
	Text graj, exits, title;
	font.loadFromFile("Textures/cour.ttf");
	graj.setFont(font);
	graj.setString("GRAJ");
	graj.setPosition(570, 350);
	graj.setFillColor(Color::Blue);
	graj.setCharacterSize(60);
	exits.setFont(font);
	exits.setString("WYJDZ");
	exits.setPosition(560, 470);
	exits.setFillColor(Color::White);
	exits.setCharacterSize(60);
	
	//tlomenu
	Texture menutext1;
	menutext1.loadFromFile("Textures/SNAKE.png");
	Sprite drewno1;
	drewno1.setTexture(menutext1);
	drewno1.setPosition(380, 20);
	

	//poczatkowy owoc
	Owoc jablko;
	jablko.x = 1;
	jablko.y = 1;
	// poczatkowa bomba
	Bomb bomb;
	bomb.x = 4;
	bomb.y = 7;
	Bomb bomb2;
	bomb2.x = -2;
	bomb2.y = -1;
	Bomb bomb3;
	bomb3.x = 31;
	bomb3.y = -1;
	//czcionka
	Text pointtext;
	pointtext.setFont(font);
	pointtext.setFillColor(Color::Black);
	pointtext.setPosition(600, 0);
	pointtext.setOutlineThickness(1);
	//window
	sf::RenderWindow oknoAplikacji(sf::VideoMode(X*pix, Y*pix, 32), "Snake" ,Style::Fullscreen);

	////////////////////////////TEKSTURY////////////////////////////////////////////////

	//tlo
	Texture grasstext;
	//grasstext.loadFromFile("Textures/grass.jpg");
	grasstext.loadFromFile("Textures/abc.png");
	Sprite grass;
	grass.setTexture(grasstext);
	grass.setScale(1.35, 1);

	//tlomenu
	Texture menutext;
	menutext.loadFromFile("Textures/tlodrewno.jpg");
	Sprite drewno;
	drewno.setTexture(menutext);
	drewno.setScale(1.5, 1.333333334);

	//cialo
	sf::Texture tekstura;
	tekstura.loadFromFile("Textures/cialo3.png");
	sf::Sprite obrazek;
	obrazek.setTexture(tekstura);
	//cialo dol
	sf::Texture cialot;
	cialot.loadFromFile("Textures/cialodol3.png");
	sf::Sprite cialodol;
	cialodol.setTexture(cialot);

	//owoc
	sf::Texture tekstura3;
	tekstura3.loadFromFile("Textures/apple.png");
	sf::Sprite obrazek3;
	obrazek3.setTexture(tekstura3);

	//bomba
	sf::Texture tekstura4;
	tekstura4.loadFromFile("Textures/bomb.png");
	sf::Sprite purp;
	purp.setTexture(tekstura4);
	Sprite bomb2s;
	bomb2s.setTexture(tekstura4);
	Sprite bomb3s;
	bomb3s.setTexture(tekstura4);
	//headprawo
	sf::Texture tekstura5;
	tekstura5.loadFromFile("Textures/glowaprawo.png");
	sf::Sprite headprawo;
	headprawo.setTexture(tekstura5);
	//headlewo
	sf::Texture tekstura6;
	tekstura6.loadFromFile("Textures/glowalewo.png");
	sf::Sprite headlewo;
	headlewo.setTexture(tekstura6);
	//headgora
	sf::Texture tekstura7;
	tekstura7.loadFromFile("Textures/glowagora.png");
	sf::Sprite headgora;
	headgora.setTexture(tekstura7);
	//headdol
	sf::Texture tekstura8;
	tekstura8.loadFromFile("Textures/glowadol.png");
	sf::Sprite headdol;
	headdol.setTexture(tekstura8);
	
	//time
	Clock clock;
	float timer = 0;
	float delay = 0.07;

	float timer2 = 0;
	float delay2 = 0.5;

	while (oknoAplikacji.isOpen())
	{
		oknoAplikacji.setFramerateLimit(60);
		oknoAplikacji.setMouseCursorVisible(false);
		//time
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		timer2 += time;
		
		//events
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				oknoAplikacji.close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up || zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::W)
			{
				ster.down = 0;
				ster.lefts = 0;
				ster.rights = 0;
				ster.up = 1;
				menu.up2 = 1;
			}
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down  || zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::S)
			{
				ster.down = 1;
				ster.lefts = 0;
				ster.rights = 0;
				ster.up = 0;
				menu.down2 = 1;
			}
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right || zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::D)
			{
				ster.down = 0;
				ster.lefts = 0;
				ster.rights = 1;
				ster.up = 0;
			}
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left || zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::A)
			{
				ster.down = 0;
				ster.lefts = 1;
				ster.rights = 0;
				ster.up = 0;
			}

		}
		if (menu.wybor == 0)
		{
			menu.menu(font, graj, exits);
			oknoAplikacji.draw(drewno);
			oknoAplikacji.draw(drewno1);
			oknoAplikacji.draw(graj);
			oknoAplikacji.draw(exits);
		}
		else if (menu.wybor == 2) oknoAplikacji.close();
		else if (menu.wybor == 1)
			{
				if (timer > delay)
				{
					timer = 0;
					ruch(vec, ster, sizes, tekst, jablko, bomb, bomb2, bomb3);
					if (timer2 > delay2)
					{
						timer2 = 0;
						if (tekst > 2)
						{
							if (bomb2.gora == 1)
							{
								bomb2.x -= 2;
								bomb2.y -= 1;
								
							}
							if (bomb2.dol == 1)
							{
								bomb2.x +=  2;
								bomb2.y +=  1;
								
							}
						}
						if (tekst > 4)
						{
							if (bomb3.gora == 1)
							{
								bomb3.x += 2;
								bomb3.y -= 1;

							}
							if (bomb3.dol == 1)
							{
								bomb3.x -= 2;
								bomb3.y += 1;

							}
						}
					}
				}
				oknoAplikacji.clear();
				oknoAplikacji.draw(grass);
				//cialo
				for (int i = 0; i < sizes; i++)
				{
					if (i == 0)
					{
						if (ster.down == 1)
							headdol.setPosition(vec[i].x*pix, vec[i].y*pix);
						if (ster.up == 1)
							headgora.setPosition(vec[i].x*pix, vec[i].y*pix);
						if (ster.lefts == 1)
							headlewo.setPosition(vec[i].x*pix, vec[i].y*pix);
						if (ster.rights == 1)
							headprawo.setPosition(vec[i].x*pix, vec[i].y*pix);
					}
					else
					{
						
						if (ster.up == 1)
						{
							cialodol.setPosition(vec[i].x*pix, vec[i].y*pix);
							oknoAplikacji.draw(cialodol);
							oknoAplikacji.draw(headgora);
						}
						if (ster.down == 1)
						{
							cialodol.setPosition(vec[i].x*pix, vec[i].y*pix);
							oknoAplikacji.draw(cialodol);
							oknoAplikacji.draw(headdol);
						}
						if (ster.rights == 1)
						{
							obrazek.setPosition(vec[i].x*pix, vec[i].y*pix);
							oknoAplikacji.draw(obrazek);
							oknoAplikacji.draw(headprawo);
						}
						if (ster.lefts == 1)
						{
							obrazek.setPosition(vec[i].x*pix, vec[i].y*pix);
							oknoAplikacji.draw(obrazek);
							oknoAplikacji.draw(headlewo);
						}
					}
				}
				//owoc
				obrazek3.setPosition(jablko.x*pix, jablko.y*pix);
				oknoAplikacji.draw(obrazek3);
				//bomba
				purp.setPosition(bomb.x*pix, bomb.y*pix);
				oknoAplikacji.draw(purp);
				bomb2s.setPosition(bomb2.x*pix, bomb2.y*pix);
				oknoAplikacji.draw(bomb2s);
				bomb3s.setPosition(bomb3.x*pix, bomb3.y*pix);
				oknoAplikacji.draw(bomb3s);
				//text
				ostringstream ss;
				ss << tekst;
				string str = ss.str();
				pointtext.setString("Punkty: " + str);
				oknoAplikacji.draw(pointtext);
			}
			//display
				oknoAplikacji.display();
	}
	return 0;
}