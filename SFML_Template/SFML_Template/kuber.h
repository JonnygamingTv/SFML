#pragma once
#include <SFML/Graphics.hpp>

class kuber
{
	//Det Som finns innanf�r public kan alla �ndra/komm� �t
public:
	kuber();
	void render(sf::RenderWindow& win);
	void setPosition(int x, int y); //funktion f�r variabel .setposition(x,y)
	float getPos(bool y = false);
	sf::Vector2f size(); // f� storleken
	//float getPos(bool y = false);
private: //Det som finns innanf�r private kan bara �garen av klassen �ndra/komma �t
	void Init();
	//Funktion f�r kvadrat/rektangel
	sf::RectangleShape base;

};