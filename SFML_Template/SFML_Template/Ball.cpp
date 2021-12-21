#include "Ball.h"
#include <SFML/Graphics.hpp>
Ball::Ball()
{
	Init();
}
void Ball::render(sf::RenderWindow& win)
{
	win.draw(this->Base);
}

void Ball::update()
{
	this->Base.move(dir[0], dir[1]);
}
void Ball::invert(int i) { dir[i] = -dir[i]; }
void Ball::setSpeed(int i, float ii) { dir[i] = ii; }

void Ball::move(int x, int y)
{
	this->Base.move(x, y);
}
float Ball::getPos(bool y)
{
	return (y ? this->Base.getPosition().y : this->Base.getPosition().x);
}
void Ball::setPos(int x, int y) {
	this->Base.setPosition(x, y);
}
float Ball::getWidth()
{
	return this->Base.getRadius();
}

bool Ball::flying() {
	return this->flight;
}
void Ball::Init()
{
	this->Base.setRadius(this->r);
	this->Base.setFillColor(sf::Color::Green);
	this->Base.setPosition(50, 930);
}
void Ball::Start() {
	if (!this->flight) {
		this->flight = true;
		//std::thread thr(Start);
	}
}
void Ball::Stop() {
	this->flight = false;
}