#pragma once

#include "graph_node.h"
#include "edge.h"
#include <vector>

using std::vector;

class Graph {
    public:
        GraphNode *addNode(string name); //Adding a node.
        Edge *addEdge(GraphNode *person, GraphNode *pal, int level); //Adding an edge.
        bool removeNode(string name); //Removing a node... NOT REQUIRED
        bool removeEdge(string person, string pal); //Removing an edge.. NOT REQUIRED

        bool nodeExists(string name); //Seeing if a node exists.
        bool edgeExists(string person, string pal); //Seeing if an edge exits.
        
        string toString(); //Turning the graph into a list that could be printed out.
        string shortestPath(string name); //Shortest path algorithm from certain node.
        string minimumSpanningTree(); //Minimum spanning tree. 

    private:
        vector<GraphNode *> nodes; //Vector with all nodes of graph.
        vector<Edge *> edges; //Vector with all edges of graph.
        GraphNode *findNodeHelper(string name); //Helper function to find node.
        Edge *findEdgeHelper(string person, string pal); //Helper function to find edge.
        bool findConnectivity(vector<GraphNode *> allNodes, vector<Edge *> allEdges, GraphNode *first, GraphNode *last); //Failed function that I did not end up using but keeping in to show my work process.
};