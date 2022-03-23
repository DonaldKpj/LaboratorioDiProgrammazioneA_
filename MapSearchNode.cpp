

#include "MapSearchNode.h"
#include <math.h>
#include <iostream>
#include "stlastar.h"
#include "Personaggio.h"
#include "Mappa.h"
using namespace std;

#define TILE 32

bool MapSearchNode::isSameState(MapSearchNode &rhs ){
    // same state in a maze search is simply when (x,y) are the same
    if( (x == rhs.x) && (y == rhs.y) )
        return true;
    return false;
}

void MapSearchNode::printNodeInfo(){
    Personaggio::crea().setCoordinate(x*TILE,y*TILE);
    char str[100];
    sprintf( str, "Node position : (%d,%d)\n", x,y );
    cout << str;
}

// Stima della distanza da un nodo al goal

float MapSearchNode::goalDistanceEstimate(MapSearchNode &nodeGoal ){
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::isGoal(MapSearchNode &nodeGoal ){
    if( (x == nodeGoal.x) && (y == nodeGoal.y) )
        return true;
    return false;
}

// Genera il successore di un nodo dato usando AddSuccessor, una funzione helper della classe A*
bool MapSearchNode::getSuccessors(AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node ){
    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }


    MapSearchNode NewNode;

    // "prova" ogni possibile mossa eccetto il backwardw

    if( (Mappa::crea().getMap(x - 1, y) < 9)
        && !((parent_x == x-1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (Mappa::crea().getMap(x, y - 1) < 9)
        && !((parent_x == x) && (parent_y == y-1))
            )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (Mappa::crea().getMap(x + 1, y) < 9)
        && !((parent_x == x+1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }


    if( (Mappa::crea().getMap(x, y + 1) < 9)
        && !((parent_x == x) && (parent_y == y+1))
            )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

// Il costo dei movimenti è dato dal tipo di terreno della mappa

float MapSearchNode::getCost(MapSearchNode &successor ){
    return (float) Mappa::crea().getMap(x, y);

}