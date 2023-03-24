#pragma once

#include "graph_node.h"

struct GraphNode;

struct Edge { //Edge struct that connects two people together by a certain level.
    GraphNode *person; 
    GraphNode *pal; //would use "friend" but code doesn't like it :(
    int level; //level of friendship (1 is highest, 100 is lowest)
};