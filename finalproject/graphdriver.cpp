#include <iostream>

//#include "graph.h" // when debugging
#include "graph.cpp" // when running
#include "edge.h"

using std::cout;
using std::endl;

int main(){

    Graph my_graph;

    //This is technically testing nodeExists and edgeExists on an empty graph!!

    //Testing if a node that is not added to the graph yet exists.
    //Should print does not exist.
    cout << "Testing if a node that is not in the graph exists:" << endl;
    cout << "Does Tiana exist?: " << (my_graph.nodeExists("Tiana") ? "Tiana exists!" : "Tiana does not exists :(") << "\n" << endl;

    //Testing if a node that is not added to the graph yet exists.
    //Should print does not exist.
    cout << "Testing if an edge that is not added to graph exists:" << endl;
    cout << "Does Tiana and Cathy's friendship exist?: " << (my_graph.edgeExists("Tiana", "Cathy") ? "The friendship exists!" : "The friendship does not exist :(") << "\n" << endl;

    //Add nodes to graph.
    GraphNode *miche = my_graph.addNode("Miche");
    GraphNode *tiana = my_graph.addNode("Tiana");
    GraphNode *cathy = my_graph.addNode("Cathy");
    GraphNode *megan = my_graph.addNode("Megan");

    //Add edges to graph.
    Edge *tia_meg = my_graph.addEdge(tiana, megan, 70);
    Edge *tia_cat = my_graph.addEdge(tiana, cathy, 80);

    //Test when node is added.
    //Should print that node exists.
    cout << "Testing a node that is added to the graph exists:" << endl;
    cout << "Does Tiana exist?: " << (my_graph.nodeExists("Tiana") ? "Tiana exists!" : "Tiana does not exists :(") << "\n" << endl;
    
    //Test when edge is added.
    //Should print that edge exists.
    cout << "Testing an edge that is added to graph exists:" << endl;
    cout << "Does Tiana and Cathy's friendship exist?: " << (my_graph.edgeExists("Tiana", "Cathy") ? "The friendship exists!" : "The friendship does not exist :(") << "\n" << endl;

    //Print the current graph out.
    //I will draw out the expected graphs in a document in the repo. 
    cout << "Current graph: \n" << my_graph.toString() << endl;

    //Testing on simple case.
    cout << "Tesing shortest path on simple case: \n" << endl;
    cout << "Shortest Path from Tiana: \n" << my_graph.shortestPath("Tiana") << endl;

    //Testing on little bit more complex case.
    Edge *meg_mich = my_graph.addEdge(megan, miche, 20);
    Edge *cat_mich = my_graph.addEdge(cathy, miche, 60);

    cout << "Testing shortest path on more complex case: \n" << endl;
    cout << "Current graph: \n" << my_graph.toString() << endl;
    cout << "Shortest Path from Tiana: \n" << my_graph.shortestPath("Tiana") << endl;

    //Testing from different node.
    cout << "Testing shortest path from different node: \n" << endl;
    cout << "Shortest Path from Miche: \n" << my_graph.shortestPath("Miche") << endl;

    //Minimum spanning tree on basic tree.
    cout << "Testing MST on basic tree: \n" << endl;
    cout << "Current graph: \n" << my_graph.toString() << endl;
    cout << "Minimum Spanning Tree: \n" << my_graph.minimumSpanningTree() << "\n" << endl;

    //Minimum spanning tree on more complex tree.
    GraphNode *helen = my_graph.addNode("Helen");
    GraphNode *vyna = my_graph.addNode("Vyna");
    GraphNode *grace = my_graph.addNode("Grace");

    Edge *mich_he = my_graph.addEdge(miche, helen, 90);
    Edge *he_vyna = my_graph.addEdge(helen, vyna, 85);
    Edge *cat_grace = my_graph.addEdge(cathy, grace, 50);

    cout << "Testing MST on more complex case: \n" << endl;
    cout << "Current graph: \n" << my_graph.toString() << endl;
    cout << "Minimum Spanning Tree: \n" << my_graph.minimumSpanningTree() << "\n" << endl;

    //Testing shortest path and MST on empty graph.
    Graph empty_graph;

    cout << "Testing on empty graph \n" << endl;
    cout << "Current graph: \n" << empty_graph.toString() << endl;

    //Should print that node does not exist.
    cout << "Shortest Path from Miche: \n" << empty_graph.shortestPath("Miche") << "\n" << endl;

    //Should print that this is an empty graph.
    cout << "Minimum Spanning Tree: \n" << empty_graph.minimumSpanningTree() << "\n" << endl;


    return 0;
}