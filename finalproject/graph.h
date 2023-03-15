#pragma once

#include "graph_node.h"
#include "edge.h"

class Graph {
    public:
        bool addNode(string name);
        bool addEdge(string person, string pal, int level);
        bool removeNode(string name); 
        bool removeEdge(string person, string pal); 

        bool nodeExists(string name);
        bool edgeExists(string person, string pal);
        
        string toString();
            /*
                a -> b, c, e
                b -> d, q
                c -> a, b, e, q
                ...
            */

        string shortestPath(string name); // single-source shortest path
        string minimumSpanningTree();

    private:
        GraphNode *findNodeHelper(string name);
        Edge *findEdgeHelper(string person, string pal);
};