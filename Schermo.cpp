//
// Created by Donald Kapaj on 16/03/2022.
//

#include "Schermo.h"
#include "Mappa.h"
#include "Personaggio.h"
#include "Obbiettivo.h"
#include "stlastar.h"
#include "MapSearchNode.h"

#define TILE 32



Schermo::~Schermo() = default;


Schermo::Schermo() {
    Mappa::crea().load();
    view.setSize(Mappa::crea().getRows()*TILE, Mappa::crea().getColumns()*TILE);
    view.setCenter(Mappa::crea().getRows()*TILE/2, Mappa::crea().getColumns()*TILE/2);
    window.create(VideoMode(800,600),"Algoritmo A*");
    window.setFramerateLimit(60); //Limit the framerate to a maximum fixed frequenc,Parameters: Framerate limit, in frames per seconds

}

void Schermo::generaSchermo(Obbiettivo obbiettivo) {

    while (window.isOpen()) {
        while (window.pollEvent(event)) { //Pop the event on top of the event queue, if any, and return it.
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setView(view); //Change the current active view
        window.setActive(); //Activate or deactivate the window as the current target for OpenGL rendering.
        window.clear();
        Mappa::crea().disegnaMappa(window);
        obbiettivo.drawPersonaggio(window);

        if (!eseguito)
            aStar(obbiettivo);
        this->setEseguito(true);

        times=clock.getElapsedTime(); //returns the time elapsed since the last call to restart()

        if(times.asSeconds()>1){
            Personaggio::crea().setPos();
            clock.restart(); //puts the time counter back to zero
        }

        Personaggio::crea().disegnaPersonaggio(window);
        window.display();
    }

}

void Schermo::aStar(Obbiettivo obbiettivo) {

    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;

    while (SearchCount < NumSearches) {

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = Personaggio::crea().getX();
        nodeStart.y = Personaggio::crea().getY();
        cout << "Punto di partenza (" << nodeStart.x << "," << nodeStart.y << ")" << endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = obbiettivo.getX();
        nodeEnd.y = obbiettivo.getY();
        cout << "Punto di arrivo (" << nodeEnd.x << "," << nodeEnd.y << ")" << endl;

        // Set Start and goal states
        astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do {
            SearchState = astarsearch.SearchStep();
            SearchSteps++;
        } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
            cout << "Search found goal state\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();
            int steps = 0;
            node->printNodeInfo();
            for (;;) {
                node = astarsearch.GetSolutionNext();
                if (!node) {
                    break;
                }
                node->printNodeInfo();
                steps++;
            }

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();

        } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
            cout << "Search terminated. Did not find goal state\n";
        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount++;
        astarsearch.EnsureMemoryFreed();
    }
}

void Schermo::setEseguito(bool eseguito) {
    Schermo::eseguito = eseguito;
}