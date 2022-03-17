

#ifndef LABORATORIODIPROGRAMMAZIONEA__SCHERMO_H
#define LABORATORIODIPROGRAMMAZIONEA__SCHERMO_H


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Obbiettivo.h"
#include "Personaggio.h"

using namespace sf;

class Schermo {
public:
    Schermo();
    ~Schermo();
    void generaSchermo(Obbiettivo obbiettivo);
    void Astar( Obbiettivo obbiettivo);

private:
    View view; //a camera in the 2D scene
    Time times; //encapsulates a time value in a flexible way
    Clock clock;// a lightweight class for measuring time.
    bool eseguito = false;
public:
    void setEseguito(bool eseguito);

private:
    sf::Event event; //holds all the informations about a system event that just happened
    sf::RenderWindow window; //is the main class of the Graphics module



};


#endif //LABORATORIODIPROGRAMMAZIONEA__SCHERMO_H
