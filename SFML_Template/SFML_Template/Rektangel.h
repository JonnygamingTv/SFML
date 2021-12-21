#pragma once
#include <SFML/Graphics.hpp>
class Rektangel
{
public:
    Rektangel();
    void render(sf::RenderWindow& win);
    void move(int x, int y);
    float getPos(bool y = false);
    float getWidth(bool y = false);
private:
    void Init();
    float speed = 0.1f;
    int xl = 120;
    int yl = 20;
    sf::RectangleShape Base;
};

