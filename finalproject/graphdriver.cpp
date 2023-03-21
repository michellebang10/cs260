#include <iostream>

//#include "graph.h" // when debugging
#include "graph.cpp" // when running
#include "edge.h"

using std::cout;
using std::endl;

int main(){

    Graph my_graph;

    GraphNode *miche = my_graph.addNode("Miche");
    GraphNode *tiana = my_graph.addNode("Tiana");
    GraphNode *cathy = my_graph.addNode("Cathy");
    GraphNode *megan = my_graph.addNode("Megan");

    Edge *tia_meg = my_graph.addEdge(tiana, megan, 70);
    Edge *tia_cat = my_graph.addEdge(tiana, cathy, 80);

    cout << "my_graph.to_string: " << my_graph.toString() << endl;

    cout << "Does Tiana exist?: " << (my_graph.nodeExists("Tiana") ? "Tiana exists!" : "Tiana does not exists :(") << endl;
    cout << "Does Tiana and Cathy's friendship exist?: " << (my_graph.edgeExists("Tiana", "Cathy") ? "The friendship exists!" : "The friendship does not exist :(") << endl;

    cout << "Does Bob exist?: " << (my_graph.nodeExists("Bob") ? "Bob exists!" : "Bob does not exists :(") << endl;
    cout << "Does Tiana and Michelle's friendship exist?: " << (my_graph.edgeExists("Tiana", "Miche") ? "The friendship exists!" : "The friendship does not exist :(") << endl;

    //testing on simple case
    cout << "Shortest Path from Tiana: \n" << my_graph.shortestPath(tiana) << endl;

    //testing on little bit more complex case
    Edge *meg_mich = my_graph.addEdge(megan, miche, 20);
    Edge *cat_mich = my_graph.addEdge(cathy, miche, 60);

    cout << "Shortest Path from Tiana: \n" << my_graph.shortestPath(tiana) << endl;

    //testing from different node
    cout << "Shortest Path from Miche: \n" << my_graph.shortestPath(miche) << endl;

    cout << "Minimum spanning tree: \n" << my_graph.minimumSpanningTree() << endl;


    return 0;
}