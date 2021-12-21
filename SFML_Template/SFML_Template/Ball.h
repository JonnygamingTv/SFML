#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
public:
    Ball();
    void render(sf::RenderWindow& win);
    void update();
    void move(int x, int y = 0);
    float getPos(bool y = false);
    void setPos(int x, int y);
    float getWidth();
    void Start();
    void invert(int i = 0);
    void setSpeed(int i = 0, float ii = 0);
    void Stop();
    bool flying();

private:
    bool flight = false;
    int r = 7;
    void Init();
    sf::CircleShape Base;
    //std::thread thr;
    float dir[2] = { 0,-0.2f };
};

