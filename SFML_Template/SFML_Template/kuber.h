#pragma once
#include <SFML/Graphics.hpp>

class kuber
{
	//Det Som finns innanför public kan alla ändra/kommå åt
public:
	kuber();
	void render(sf::RenderWindow& win);
	void setPosition(int x, int y); //funktion för variabel .setposition(x,y)
	float getPos(bool y = false);
	sf::Vector2f size(); // få storleken
	//float getPos(bool y = false);
private: //Det som finns innanför private kan bara ägaren av klassen ändra/komma åt
	void Init();
	//Funktion för kvadrat/rektangel
	sf::RectangleShape base;

};