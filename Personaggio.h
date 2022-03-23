

#ifndef LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H
#define LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H


#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaggio {

private:
    int x, y;
    Personaggio();
    Personaggio(int x, int y);
    Sprite sprite;
    Texture texture;
    vector<Vector2f> coordinate;
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
    void disegnaPersonaggio(RenderWindow &window);


};


#endif //LABORATORIODIPROGRAMMAZIONEA__PERSONAGGIO_H
