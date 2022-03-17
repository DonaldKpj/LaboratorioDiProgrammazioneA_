//
// Created by Donald Kapaj on 16/03/2022.
//

#include "Obbiettivo.h"
#include "Mappa.h"
#define TILE 32

Obbiettivo::Obbiettivo() {
    int xf;
    int yf;
    do {
        xf = static_cast<int>(random() % Mappa::crea().getColumns());
        yf = static_cast<int>(random() % Mappa::crea().getRows());
    }while (Mappa::crea().getTiles(xf,yf) >= 9);
    this->x=xf;
    this->y= yf;
    texture.loadFromFile("PreciousOne.png");
    sprite.setTexture(texture);
    sprite.scale(0.06,0.06);
    sprite.setPosition(y*TILE,x*TILE);
}

Obbiettivo::~Obbiettivo() {

}

int Obbiettivo::getX() const {
    return x;
}

void Obbiettivo::setX(int x) {
    Obbiettivo::x = x;
}

int Obbiettivo::getY() const {
    return y;
}

void Obbiettivo::setY(int y) {
    Obbiettivo::y = y;
}

void Obbiettivo::setpos(int x, int y) {
    Obbiettivo::sprite.setPosition(x,y);

}

void Obbiettivo::drawPersonaggio(RenderWindow &window) {
    window.draw(sprite);

}

Obbiettivo::Obbiettivo(int x, int y) {
    this->x=x;
    this->y= y;
    texture.loadFromFile("PreciousOne.png");
    sprite.setTexture(texture);
    sprite.scale(0.06,0.06);
    sprite.setPosition(y*TILE,x*TILE);

}