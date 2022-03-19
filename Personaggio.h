

#ifndef LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H
#define LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H


#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaggio {

private:
    Personaggio();
    Personaggio(int x, int y);
    int x;
    int y;
    vector<Vector2f> coordinate;
    Sprite sprite;
    Texture texture;
    int index=0;


public:
    int getX() const;
    int getY() const;
    void setPos();
    void setPos(int x, int y);
    void setCoordinate(int x, int y);
    int getIndex() const;
    static Personaggio&crea();
    static Personaggio&crea(int x, int y);
    const vector<Vector2f> &getCoordinate() const;
    void DisegnaPersonaggio(RenderWindow &window);


};


#endif //LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H
