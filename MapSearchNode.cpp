//
// Created by Donald Kapaj on 16/03/2022.
//


#include "MapSearchNode.h"
#include <math.h>
#include <iostream>
#include "stlastar.h"
#include "Personaggio.h"
#include "Mappa.h"
using namespace std;

#define TILE 32

bool MapSearchNode::IsSameState( MapSearchNode &rhs ){
    // same state in a maze search is simply when (x,y) are the same
    if( (x == rhs.x) && (y == rhs.y) )
        return true;
    return false;
}

void MapSearchNode::PrintNodeInfo(){
    Personaggio::crea().setCoordinate(x*TILE,y*TILE);
    char str[100];
    sprintf( str, "Node position : (%d,%d)\n", x,y );
    cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal.

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal ){
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal ){
    if( (x == nodeGoal.x) && (y == nodeGoal.y) )
        return true;
    return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node ){
    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }


    MapSearchNode NewNode;

    // push each possible move except allowing the search to go backwards

    if( (Mappa::crea().GetMap( x-1, y ) < 9)
        && !((parent_x == x-1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (Mappa::crea().GetMap( x, y-1 ) < 9)
        && !((parent_x == x) && (parent_y == y-1))
            )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (Mappa::crea().GetMap( x+1, y ) < 9)
        && !((parent_x == x+1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }


    if( (Mappa::crea().GetMap( x, y+1 ) < 9)
        && !((parent_x == x) && (parent_y == y+1))
            )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor ){
    return (float)Mappa::crea().GetMap( x, y );

}