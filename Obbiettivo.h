//
// Created by Donald Kapaj on 16/03/2022.
//

#ifndef LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H
#define LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H


#include <SFML/Graphics.hpp>
using namespace sf;



class Obbiettivo {
public:
    Obbiettivo();
    Obbiettivo(int x, int y);
    virtual ~Obbiettivo();
    void drawPersonaggio(RenderWindow &window);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setpos(int x, int y);

private:
    Sprite sprite;
    Texture texture;
    int x;
    int y;

};


#endif //LABORATORIODIPROGRAMMAZIONEA__OBBIETTIVO_H
