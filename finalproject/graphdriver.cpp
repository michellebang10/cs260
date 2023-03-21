#include <iostream>

#include "graph.h"
//#include "graph.h" // when debugging
#include "graph.cpp" // when running
#include "edge.h"

using std::cout;
using std::endl;

int main(){

    Graph my_graph;

    GraphNode *michelle = my_graph.addNode("Michelle");
    GraphNode *tiana = my_graph.addNode("Tiana");
    GraphNode *cathy = my_graph.addNode("Cathy");
    GraphNode *megan = my_graph.addNode("Megan");

    Edge *tia_meg = my_graph.addEdge(tiana, megan, 70);
    Edge *tia_cat = my_graph.addEdge(tiana, cathy, 80);

    cout << "my_graph.to_string: " << my_graph.toString() << endl;

    cout << "Does Tiana exist?: " << (my_graph.nodeExists("Tiana") ? "Tiana exists!" : "Tiana does not exists :(") << endl;
    cout << "Does Tiana and Cathy's friendship exist?: " << (my_graph.edgeExists("Tiana", "Cathy") ? "The friendship exists!" : "The friendship does not exist :(") << endl;

    cout << "Does Bob exist?: " << (my_graph.nodeExists("Bob") ? "Bob exists!" : "Bob does not exists :(") << endl;
    cout << "Does Tiana and Michelle's friendship exist?: " << (my_graph.edgeExists("Tiana", "Michelle") ? "The friendship exists!" : "The friendship does not exist :(") << endl;


    cout << "Shortest Path from Tiana: " << my_graph.shortestPath(tiana) << endl;


    return 0;
}