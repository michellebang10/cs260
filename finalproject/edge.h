#pragma once

#include "graph_node.h"

struct Edge {
    GraphNode *person;
    GraphNode *pal; // would use "friend" but code doesn't like it :(
    int level; // level of friendship (1 is highest, 100 is lowest)
};