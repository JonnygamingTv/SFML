#include "Meny.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Meny::Meny()
{
    Init();
}
void Meny::render(sf::RenderWindow& win) {
    win.draw(this->txt);
}
void Meny::move(int x, int y) {
    this->txt.move(x, y);
}
int Meny::getSize() {
    return this->txt.getCharacterSize();
}
void Meny::setPosition(float x, float y) {
    this->txt.setPosition(x, y);
}
void Meny::setContent(char* content)
{
    this->txt.setString(content);
}
sf::Vector2f Meny::getpos() {
    return this->txt.getPosition();
}
float Meny::getWidth() {
    return this->txt.getGlobalBounds().width;
}

void Meny::Init()
{
    this->txt.setFillColor(sf::Color::Red);
    this->txt.setPosition(415, 400);
    this->txt.setCharacterSize(100);
    this->txt.setLetterSpacing(1);
    if (!this->font.loadFromFile("arial.ttf")) {
        std::cout << "Use LeftClick + Backspace";
    }
    else { this->txt.setFont(this->font); }
}
