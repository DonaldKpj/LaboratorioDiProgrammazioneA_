#ifndef LABORATORIODIPROGRAMMAZIONEA__MAPPA_H
#define LABORATORIODIPROGRAMMAZIONEA__MAPPA_H


#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Mappa {

private:
    Mappa(int dim);
    Mappa(char x);
    Texture tex;
    VertexArray m_vertices;
    sf::RenderStates states;
    enum Mappe : char{mappa1 = 'a',mappa2 = 'b' ,mappa3 = 'c'};
    int rows=0;
    int columns=0;
    vector<vector<int>>tiles;

public:
    static Mappa&crea(char x);
    static Mappa&crea(int dim =rand()%3 );
    int getColumns() const;
    int getRows() const ;
    int GetMap(int x, int y);
    void findDimension();
    bool load();
    void DisegnaMappa(RenderWindow &window);
    int getTiles(int x, int y) const;

};



#endif //LABORATORIODIPROGRAMMAZIONEA__MAPPA_H
