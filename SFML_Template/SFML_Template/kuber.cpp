#include "kuber.h"
#include <SFML/Graphics.hpp>
kuber::kuber()
{
	Init();

}

void kuber::render(sf::RenderWindow& win)
{
	win.draw(base);
}

void kuber::setPosition(int x, int y) { // variabel.setPosition(x,y)
	this->base.setPosition(x, y);
}

float kuber::getPos(bool y)
{
	if(y)return this->base.getPosition().y;
	return this->base.getPosition().x;
}
sf::Vector2f kuber::size() {
	return this->base.getSize();
}

void kuber::Init()
{
	// fixar storleken, färgen och positionen på kuben.
	sf::Vector2f bg;
	bg.x = 40;
	bg.y = 40;
	this->base.setSize(bg);
	this->base.setFillColor(sf::Color::Blue);
	this->base.setOutlineColor(sf::Color::Black);
	this->base.setOutlineThickness(10);
	this->base.setPosition(0, 0);
}