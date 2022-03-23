

#ifndef LABORATORIODIPROGRAMMAZIONEA__MAPSEARCHNODE_H
#define LABORATORIODIPROGRAMMAZIONEA__MAPSEARCHNODE_H

#include "stlastar.h"
#include "Mappa.h"

class MapSearchNode{

public:
    int x;	 // the (x,y) positions of the node
    int y;
    Mappa *map;

    MapSearchNode() { x = y = 0;}
    MapSearchNode( int px, int py ) { x=px; y=py;  }

    float goalDistanceEstimate(MapSearchNode &nodeGoal );
    bool isGoal(MapSearchNode &nodeGoal );
    bool getSuccessors(AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float getCost(MapSearchNode &successor );
    bool isSameState(MapSearchNode &rhs );
    void printNodeInfo();


};


#endif //LABORATORIODIPROGRAMMAZIONEA__MAPSEARCHNODE_H
