

#include <iostream>
#include "Personaggio.h"
#include "Mappa.h"
#define TILE 32


int Personaggio::getY() const {
    return y;
}

int Personaggio::getX() const {
    return x;
}

void Personaggio::DisegnaPersonaggio(RenderWindow &window) {
    window.draw(sprite);
}

void Personaggio::setPos(int x, int y) {
    this->x = x;
    this->y = y;

}


void Personaggio::setPos() {
    if(index!=coordinate.size())
        Personaggio::sprite.setPosition(coordinate[index++]);
}


Personaggio::Personaggio() {
    int xi;
    int yi;
    do {
        xi = static_cast<int>(random() %  Mappa::crea().getColumns());
        yi = static_cast<int>(random() % Mappa::crea().getRows());
    }while (Mappa::crea().getTiles(xi,yi) >= 9);
    this->x=xi;
    this->y=yi;

    texture.loadFromFile("Gollum.png");
    sprite.setTexture(texture);
    sprite.scale(0.04,0.04);
    sprite.setPosition(y*TILE,x*TILE);
    index=0;

}

Personaggio &Personaggio::crea() {
    static Personaggio personaggio;
    return personaggio;
}

const vector<Vector2f> &Personaggio::getCoordinate() const {
    return coordinate;
}

void Personaggio::setCoordinate(int x, int y) {
    Personaggio::coordinate.push_back(Vector2f(y,x));
}

int Personaggio::getIndex() const {
    return index;
}

Personaggio::Personaggio(int x, int y) {
    this->x=x;
    this->y=y;
    index=0;

}

Personaggio &Personaggio::crea(int x, int y) {
    static Personaggio personaggio(x,y);
    return personaggio;
}