#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
class Meny
{
public: // allt h�r man kan �ndra som alla kan �ndra
    Meny();
    void render(sf::RenderWindow& win);
    void move(int x, int y); // det h�r en funktion f�r flyttningen och en x axel o en y axel
    sf::Vector2f getpos(); // f� positionen
    void setPosition(float x, float y); // det h�r �r en funktion f�r tv� varabialer x o y till att s�tta positionen

    void setContent(char* content); //det h�r en funktion f�r ska s�tta en text som ska visas

    int getSize(); // f� storleken i int form
    //respons_Typ name(variabel_Typ eget_variabel_namn);
    float getWidth(); // f� bredden i float form

private: // det som �garen har tillg�ng till, som bara �garen kan �ndra
    void Init(); // det �r postionerna och f�rgarna
    sf::Text txt; // SFML funktionen f�r att skapa text
    sf::Font font;
};

