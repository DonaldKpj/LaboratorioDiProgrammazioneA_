
#include <iostream>
#include <math.h>
#include "Schermo.h"
#include "Personaggio.h"



int main() {

    srand((unsigned int)time(NULL));
    Personaggio& p = Personaggio::crea();
    Obbiettivo o;
    Schermo schermo;
    schermo.generaSchermo(o);
    return 0;
}