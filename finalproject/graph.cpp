#include "graph.h"
#include "edge.h"
#include <string>
using std::string;

// Add a node using name, returns the node added
GraphNode * Graph::addNode(string name) {
    GraphNode * new_node = new GraphNode{name, vector<Edge *>(), vector<GraphNode *>()};

    this->nodes.push_back(new_node);

    return new_node;
}

// Add an edge using person and pal as names of nodes to connect
Edge * Graph::addEdge(GraphNode *person, GraphNode *pal, int level) {
    Edge * new_edge = new Edge{person, pal, level};

    person->friendshipLevel.push_back(new_edge);
    pal->friendshipLevel.push_back(new_edge);

    person->friendship.push_back(pal);
    pal->friendship.push_back(person);

    return new_edge;
}

// Remove a node if it exists, returns true if a node is removed, false otherwise
bool Graph::removeNode(string name) {
    //use find node helper
    //friendship.erase(i)
    //friendshipLevel.erase(i)
    GraphNode * gone = findNodeHelper(name);

    if (gone != nullptr){
        return true;
    }

    return false;

}

// Remove an edge if it exists, returns true if an edge is removed, false otherwise
bool Graph::removeEdge(string person, string pal) {
    //use find edge helper
    //use friendshipLevel.erase(i)
}

// Check if a node exists with the given name, returns true if node exists, false otherwise...
bool Graph::nodeExists(string name) {
    //use find node helper...
    GraphNode * check = findNodeHelper(name);
    
    if (check != nullptr){
        return true;
    }
    return false;
}

// Check if an edge exists with the given name, returns true if edge exists, false otherwise...
bool Graph::edgeExists(string person, string pal) {
    Edge * check = findEdgeHelper(person, pal);

    if (check != nullptr){
        return true;
    }
    return false;
    //use fine edge helper...
}

string Graph::toString() {
    string result = ""; //should use a string builder
    for(int i = 0; i < this->nodes.size(); i++) { //should use iterator instead, since a vector supports iterators
        result += this->nodes.at(i)->toString() + ", ";
    }

    return result;

}

// Find shortest path from node with name to each other node that can be reached, returns a string with that information
string Graph::shortestPath(GraphNode *person) {
    string path = "";
    //helppp
    //compare person to all nodes....
    //idea: create an array/list that stores distances
    //start with inf
    //then start from the beginning and add prev.... (if possible)
    //should check lecture videos....
    for(int i = 0; i < this->nodes.size(); i ++) {
        GraphNode * tester = this->nodes.at(i);
        if (person == tester){
            path += person->name + " to " + person->name + ": 0 \n";
        } else if (edgeExists(person->name, tester->name)){
            Edge * edgeCheck = findEdgeHelper(person->name, tester->name);
            path += person->name + " to " + tester->name + ": " + std::to_string(edgeCheck->level) + "\n"; 
        } else{

        }

    }

    return path;
}

// Find a minimum spanning tree and return it.
string Graph::minimumSpanningTree() {
    string tree = "";

    //idea: keep connecting smallest edges together

    

    return tree;

}

// Start of private functions
// Finds the node with name, return pointer to that node
GraphNode *Graph::findNodeHelper(string name) {
    for(int i = 0; i < this->nodes.size(); i++){
        if (this->nodes.at(i)->name == name){
            return this->nodes.at(i);
        }
    }

    return nullptr;

}

// Finds the edge with named person and pal, return pointer to that edge
Edge *Graph::findEdgeHelper(string person, string pal) {
    //for(int i = 0; i < this->nodes.size()->friendshipLevel.size(); i ++){
    //    helppp
    //}

    //for(auto edge: this->nodes->friendshipLevel){
        //help meeee
    //}

    for(int i = 0; i < this->nodes.size(); i++){
        if (this->nodes.at(i)->name == person){
            for (int n = 0; n < this->nodes.at(i)->friendshipLevel.size(); n++){
                if (this->nodes.at(i)->friendshipLevel.at(n)->pal->name == pal){
                    return this->nodes.at(i)->friendshipLevel.at(n);
                }

            }
        }
    }

    return nullptr;
}

