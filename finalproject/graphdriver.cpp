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



    return 0;
}