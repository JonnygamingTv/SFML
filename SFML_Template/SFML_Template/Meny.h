#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
class Meny
{
public: // allt här man kan ändra som alla kan ändra
    Meny();
    void render(sf::RenderWindow& win);
    void move(int x, int y); // det här en funktion för flyttningen och en x axel o en y axel
    sf::Vector2f getpos(); // få positionen
    void setPosition(float x, float y); // det här är en funktion för två varabialer x o y till att sätta positionen

    void setContent(char* content); //det här en funktion för ska sätta en text som ska visas

    int getSize(); // få storleken i int form
    //respons_Typ name(variabel_Typ eget_variabel_namn);
    float getWidth(); // få bredden i float form

private: // det som ägaren har tillgång till, som bara ägaren kan ändra
    void Init(); // det är postionerna och färgarna
    sf::Text txt; // SFML funktionen för att skapa text
    sf::Font font;
};

