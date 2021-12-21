#include <SFML/Graphics.hpp>
#include "Rektangel.h"
#include "Ball.h"
#include "kuber.h"
#include "Meny.h"

kuber buildKvadrater[80]; // lista med objekt
void buildMap() { // bygg upp världen random
	//int row1 = rand()%10 + 45; används inte för tillfället
	int rows = 0; int rowItems = 0;
	for (int i = 0; i < rand()%40 + 40; i++) {
		rowItems++;
		if (rowItems > rand()%20 + 8) {
			rowItems = 0;
			rows++;
		}
		buildKvadrater[i].setPosition(rand()%20 + 30 + rowItems * 50, rows * 55);
	}
}
int main()
{
	bool gameON = false;
	Rektangel player[1];
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "A | D | SPACE");
	float x = 0;
	float y = 0;
	Ball boll[1];
	buildMap();
	Meny text;
	char startTxt[15] = { 'P','r','e','s','s',' ','t','o',' ','S','t','a','r','t','!'};
	text.setContent(startTxt);
	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!gameON) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)||(sf::Mouse::getPosition().x > text.getpos().x && sf::Mouse::getPosition().x < text.getpos().x + text.getWidth())) {
					buildMap();
					gameON = true;
					for (int i = 0; i < 1; i++) {
						boll[i].Stop();
						boll[i].setPos(player[0].getPos()+player[0].getWidth()/2-boll[i].getWidth()/2, player[0].getPos(true));
					}
				}
			}
			text.render(window);
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				x = x - 2;
				if (player[0].getPos() > 2)
					player[0].move(-2, 0); // flytta spelaren -2 x
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				x = x + 2;
				if (player[0].getPos() < 1500 - player[0].getWidth())player[0].move(2, 0); // flytta spelaren 2 x
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))gameON = false;
			for (int i = 0; i < 1; i++) {
				if (!boll[i].flying()) {
					boll[i].setPos(player[0].getPos()+player[0].getWidth()/2, player[0].getPos(true) - boll[i].getWidth());
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						boll[i].setSpeed(); // återställ hastigheten innan den skjuts iväg
						boll[i].Start(); // börja flyga
					}
				}
				else {
					boll[i].update(); // uppdatera bollens position
					for (int ii = 0; ii < 1; ii++) { // loopa igenom bollarna
						if (player[ii].getPos(true) < boll[i].getPos(true) && player[ii].getPos() < boll[i].getPos() + boll[i].getWidth() && player[ii].getPos() + player[ii].getWidth() > boll[i].getPos() - boll[i].getWidth()) { // är bollen i spelaren?
							boll[i].invert(1); // vänd håll på y-axeln
							boll[i].setSpeed(0,(boll[i].getPos()+boll[i].getWidth()/2- player[ii].getPos() - player[ii].getWidth() / 2)/100); // sätt hastigheten baserat på positionen på spelaren
						}
					}
					if (boll[i].getPos(true) > 1000-boll[i].getWidth()) { gameON = false; boll[i].invert(1); } // avsluta spelet om den åker utanför
					else if (boll[i].getPos(1) < 0)boll[i].invert(1); // taket
					if (boll[i].getPos() > 1500 || boll[i].getPos() < 0)boll[i].invert(0); // väggarna
					for (int ii = 0; ii < 80; ii++) // alla lådor som man ska pricka
					{
						if (boll[i].getPos() + boll[i].getWidth() > buildKvadrater[ii].getPos() && boll[i].getPos() - boll[i].getWidth() < buildKvadrater[ii].getPos() + buildKvadrater[ii].size().x && boll[i].getPos(true) < buildKvadrater[ii].getPos(true) + buildKvadrater[ii].size().y && boll[i].getPos(true) > buildKvadrater[ii].getPos(true)) {
							buildKvadrater[ii].setPosition(0, 0);
							boll[i].invert(1);
							//boll[i].invert(0);
						}
					}
				}
			}
			int bKLeft = 0;
			for (int i = 0; i < 80; i++)
			{
				if (buildKvadrater[i].getPos() > 0) {
					buildKvadrater[i].render(window); // rendera endast om det inte är på x-pos 0
					bKLeft++;
				}
			}
			if (bKLeft == 0)gameON = false;
			for(int i=0; i<1;i++)boll[i].render(window); // rendera bollarna överst (förutom spelaren)
			player[0].render(window);
		}
		// Visa alla pixlar
		window.display();
	}

	return 0;
}