

#ifndef LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H
#define LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H


#include <SFML/Graphics.hpp>
using namespace sf;



class Obbiettivo {

public:
    Obbiettivo();
    Obbiettivo(int x, int y);
    void drawPersonaggio(RenderWindow &window);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);

private:
    Sprite sprite;
    Texture texture;
    int x;
    int y;

};


#endif //LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H
