#pragma once

#include "graph_node.h"
#include "edge.h"
#include <vector>

using std::vector;

class Graph {
    public:
        GraphNode *addNode(string name);
        Edge *addEdge(GraphNode *person, GraphNode *pal, int level);
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

        string shortestPath(GraphNode *person); // single-source shortest path
        string minimumSpanningTree();

    private:
        vector<GraphNode *> nodes;
        vector<Edge *> edges;
        GraphNode *findNodeHelper(string name);
        Edge *findEdgeHelper(string person, string pal);
        bool findConnectivity(vector<GraphNode *> allNodes, vector<Edge *> allEdges, GraphNode *first, GraphNode *last);
};