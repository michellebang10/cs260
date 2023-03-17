#include <iostream>

#include "graph.h"
#include "graph.cpp"
#include "edge.h"

using std::cout;
using std::endl;

int main(){

    Graph my_graph;

    GraphNode *michelle = my_graph.addNode("Michelle");
    GraphNode *tiana = my_graph.addNode("Tiana");
    GraphNode *cathy = my_graph.addNode("Cathy");
    GraphNode *megan = my_graph.addNode("Megan");

    cout << "my_graph.to_string: " << my_graph.toString() << endl;



    return 0;
}