#include "Rektangel.h"

Rektangel::Rektangel()
{
	Init();
}

void Rektangel::render(sf::RenderWindow& win)
{
	win.draw(Base);
}

void Rektangel::move(int x, int y = 0)
{
	Base.move(x, y);
}
float Rektangel::getPos(bool y)
{
	if (y)return Base.getPosition().y;
	return Base.getPosition().x;
}
float Rektangel::getWidth(bool y)
{
	if (y)return Base.getSize().y;
	return Base.getSize().x;
}
void Rektangel::Init()
{
	sf::Vector2f gg;
	gg.x = this->xl;
	gg.y = this->yl;
	this->Base.setSize(gg);
	this->Base.setFillColor(sf::Color::Red);
	this->Base.setPosition(50, 960 - this->yl);
}
