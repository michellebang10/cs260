#include "graph.h"
#include "edge.h"
#include <string>
using std::string;

// Add a node using name, returns the node added
GraphNode * Graph::addNode(string name) { //O(1)
    GraphNode * new_node = new GraphNode{name, vector<Edge *>(), vector<GraphNode *>()};

    this->nodes.push_back(new_node);

    return new_node;
}

// Add an edge using person and pal as names of nodes to connect
Edge * Graph::addEdge(GraphNode *person, GraphNode *pal, int level) { //O(1)
    Edge * new_edge = new Edge{person, pal, level};
    Edge * new_edge2 = new Edge{pal, person, level};

    this->edges.push_back(new_edge);

    person->friendshipLevel.push_back(new_edge);
    pal->friendshipLevel.push_back(new_edge2);

    person->friendship.push_back(pal);
    pal->friendship.push_back(person);

    return new_edge;
}

// Remove a node if it exists, returns true if a node is removed, false otherwise
// NOT REQUIRED: WILL DO IF I HAVE TIME
bool Graph::removeNode(string name) {
    //use find node helper
    //friendship.erase(i)
    //friendshipLevel.erase(i)
    GraphNode * gone = findNodeHelper(name);

    if (gone != nullptr){
        //check all nodes where gone != node
        //go through friendshipLevels, delete edge with gone
        //go through friendships, delete gone
        //then go through nodes and delete gone
        return true;
    }

    return false;

}

// Remove an edge if it exists, returns true if an edge is removed, false otherwise
// NOT REQUIRED: WILL DO IF I HAVE TIME
bool Graph::removeEdge(string person, string pal) {
    //use find edge helper
    //use friendshipLevel.erase(i)
    Edge * gone = findEdgeHelper(person, pal);

    if (gone != nullptr){
        //go through person's friendships, delete pal
        //go through person's friendshipLevels, delete gone
        //go through pal's friendships, delete person
        //go through pal's friendshipLevels, delete gone
        return true;
    }

    return false;
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
}

string Graph::toString() {
    string result = ""; 
    for(int i = 0; i < this->nodes.size(); i++) { 
        result += this->nodes.at(i)->toString() + ", ";
    }

    return result;
}

// Find shortest path from node with name to each other node that can be reached, returns a string with that information
string Graph::shortestPath(GraphNode *person) { //O(n) or O(n^2) <- look at more...
    string path = "node     dist    parent\n";

    vector<GraphNode *> listNodes;
    vector<GraphNode *> queue;
    vector<GraphNode *> parent;
    vector<int> distances;
    
    listNodes.push_back(person);
    distances.push_back(0);

    for(int i = 1; i < this->nodes.size(); i++){
        distances.push_back(100000);
    }

    for(int i = 0; i < this->nodes.size(); i++){
        parent.push_back(nullptr);
    }

    GraphNode * current = person;

    bool checker = true;

    if(current->friendship.size() == 0){
        checker = false;
    }

    int counter = 0;
    for(int i = 0; i < this->nodes.size(); i++){
        if(this->nodes.at(i)->friendship.size() == 0){
            counter += 1;
        }
    }

    while (checker){
        for(int i = 0; i < current->friendship.size(); i++){
            queue.push_back(current->friendship.at(i));
        }

        for(int m = 0; m < queue.size(); m++){
            bool check = true;
            for(int n = 0; n < listNodes.size(); n++){
                if(listNodes[n] == queue[m]){
                    check = false;
                    break;
                }
            }
            if(check){
                listNodes.push_back(queue[m]);
            }
        }

        for(int z = 0; z < queue.size(); z++){
            auto it = find(listNodes.begin(), listNodes.end(), queue[z]);
            int index = it - listNodes.begin();
            Edge * edge = findEdgeHelper(current->name, queue[z]->name);
            auto it2 = find(listNodes.begin(), listNodes.end(), current);
            int i2 = it2 - listNodes.begin();
            int totEdge = edge->level + distances[i2];
            if (totEdge < distances[index]){
                distances.at(index) = totEdge;
                parent.at(index) = current;
            }
        }

        auto it2 = find(listNodes.begin(), listNodes.end(), current);
        int i2 = it2 - listNodes.begin();

        current = listNodes.at(i2 + 1);

        if(listNodes.size() == this->nodes.size() - counter){
            checker = false;
        }

        queue.clear();
    }

    for(int i = 0; i < this->nodes.size(); i++){
        bool check = true;
        for(int n = 0; n < listNodes.size(); n++){
            if(listNodes[n] == this->nodes.at(i)){
                check = false;
                break;
            }
        }
        if(check){
            listNodes.push_back(this->nodes.at(i));
        }
    }

    for(int j = 0; j < this->nodes.size(); j++){
        if(parent[j] != nullptr){
            path += listNodes[j]->name + "      " + std::to_string(distances[j]) + "      " + parent[j]->name + "\n";
        } else{
            if(distances[j] == 100000){
                path += listNodes[j]->name + "      " + "inf" + "      " + "null" + "\n";
            } else{
                path += listNodes[j]->name + "      " + std::to_string(distances[j]) + "      " + "null" + "\n";
            }
        }
    }

    

    return path;


    //OLD SCRATCH WORK:
    //compare person to all nodes....
    //idea: create an array/list that stores distances
    //start with inf
    //then start from the beginning and add prev.... (if possible)
    //should check lecture videos....
    //for(int i = 0; i < this->nodes.size(); i ++) {
        //GraphNode * tester = this->nodes.at(i);
        //if (person == tester){
        //    path += person->name + " to " + person->name + ": 0 \n";
        //} else if (edgeExists(person->name, tester->name)){
        //    Edge * edgeCheck = findEdgeHelper(person->name, tester->name);
        //    path += person->name + " to " + tester->name + ": " + std::to_string(edgeCheck->level) + "\n"; 
        //} else{

        //}

    //}
}

// Created this function for the 5th attempt of MST... did not work out well... </3
bool Graph::findConnectivity(vector<GraphNode *> allNodes, vector<Edge *> allEdges, GraphNode *first, GraphNode *last){
    for(int i = 0; i < allNodes.size(); i++){
        bool helper = edgeExists(first->name, allNodes.at(i)->name);
        if(helper){
            Edge * ehelp1 = findEdgeHelper(first->name, allNodes.at(i)->name);
            Edge * ehelp2 = findEdgeHelper(allNodes.at(i)->name, first->name);
            for(int j = 0; j < allEdges.size(); j++){
                if(ehelp1 == allEdges.at(j) || ehelp2 == allEdges.at(j)){
                    if(allNodes.at(i) == last){
                        return true;
                    }else{
                        return(findConnectivity(allNodes, allEdges, allNodes.at(i), last));
                    }  
                }
            }
        }
    }
    return false;
}

// Find a minimum spanning tree and return it.
string Graph::minimumSpanningTree() {
    string tree = "";

    //idea: keep connecting smallest edges together

    vector<Edge *> listEdge;


    for(int i = 0; i < this->edges.size(); i++){ //Creating a list of edges from the graph.
        listEdge.push_back(this->edges.at(i));
    }

    bool check = false;

    for(int i = 0; i < listEdge.size() - 1; i++){ //Sorting the edges from smallest to largest value.
        for(int j = 0; j < listEdge.size() - i - 1; j++){
            if(listEdge[j]->level > listEdge[j+1]->level){
                Edge * hold = listEdge[j];
                listEdge[j] = listEdge[j+1];
                listEdge[j+1] = hold;
                check = true;
            }
        }

        if(check == false){
            break;
        }
    }

    vector<Edge *> treeEdges;
    vector<GraphNode *> treeNodes;
    vector<GraphNode* > parentNodes;
    //vector<GraphNode *> palNodes;
    //vector<GraphNode *> perNodes;


    //SIXTH ATTEMPT

    for(int i = 0; i < this->nodes.size(); i++){
        treeNodes.push_back(nodes.at(i));
        parentNodes.push_back(nodes.at(i));
    }

    for(int i = 0; i < listEdge.size(); i++){
        GraphNode * first = listEdge.at(i)->person;
        GraphNode * last = listEdge.at(i)->pal;

        auto it = find(treeNodes.begin(), treeNodes.end(), listEdge.at(i)->person);
        int index = it - treeNodes.begin();
        auto it2 = find(treeNodes.begin(), treeNodes.end(), listEdge.at(i)->pal);
        int index2 = it2 - treeNodes.begin();

        if(parentNodes.at(index) != parentNodes.at(index2)){
            treeEdges.push_back(listEdge.at(i));
            GraphNode * oldParent = parentNodes.at(index2);
            for(int n = 0; n < parentNodes.size(); n++){
                if(parentNodes.at(n) == oldParent){
                    parentNodes.at(n) = parentNodes.at(index);
                }
            }
        }
    }


    //FIFTH ATTEMPT
    //Weird attempt where not all the edges that existed in the graph were being counted for.

    //for(int k = 0; k < listEdge.size(); k++){
    //    GraphNode * first = listEdge.at(k)->person;
    //    GraphNode * last = listEdge.at(k)->pal;
    //    bool checker = findConnectivity(treeNodes, treeEdges, first, last);
    //    if(checker == false){
    //        treeEdges.push_back(listEdge.at(k));
    //        treeNodes.push_back(listEdge.at(k)->person);
    //        treeNodes.push_back(listEdge.at(k)->pal);
    //    }
    //}




    //FOURTH ATTEMPT
    //Did not catch cycles either...

    //for(int i = 0; i < listEdge.size(); i++){
    //    bool adder = true;
        
    //    bool adder1 = true;
    //    for(int j = 0; j < treeNodes.size(); j++){
    //        bool helper = edgeExists(treeNodes.at(j)->name, listEdge.at(i)->person->name);
    //        if (helper){
    //            Edge * ehelp = findEdgeHelper(treeNodes.at(j)->name, listEdge.at(i)->person->name);
    //            Edge * ehelp2 = findEdgeHelper(listEdge.at(i)->person->name, treeNodes.at(j)->name);
    //            if(ehelp != listEdge.at(i) && ehelp2 != listEdge.at(i)){
    //                for(int k = 0; k < treeEdges.size(); k++){
    //                    if(ehelp == treeEdges.at(k) || ehelp2 == treeEdges.at(k)){
    //                        adder1 = false;
    //                    break;
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    bool adder2 = true;
    //    for(int j = 0; j < treeNodes.size(); j++){
    //        bool helper = edgeExists(treeNodes.at(j)->name, listEdge.at(i)->pal->name);
    //        if (helper){
    //            Edge * ehelp = findEdgeHelper(treeNodes.at(j)->name, listEdge.at(i)->person->name);
    //            Edge * ehelp2 = findEdgeHelper(listEdge.at(i)->person->name, treeNodes.at(j)->name);
    //            if(ehelp != listEdge.at(i) && ehelp2 != listEdge.at(i)){
    //                for(int k = 0; k < treeEdges.size(); k++){
    //                    if(ehelp == treeEdges.at(k) || ehelp2 == treeEdges.at(k)){
    //                        adder2 = false;
    //                    break;
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    if(adder1 == false && adder2 == false){
    //        adder = false;
    //    }

    //    if(adder){
    //        treeEdges.push_back(listEdge.at(i));
    //        treeNodes.push_back(listEdge.at(i)->person);
    //        treeNodes.push_back(listEdge.at(i)->pal);
    //    }
    //}


    //THIRD ATTEMPT
    //Did not catch cycles...

    //for(int i = 0; i < listEdge.size(); i++){
    //    bool adder = true;
    //    bool adderpal = true;
    //    bool adderper = true;

    //    for(int j = 0; j < parentNodes.size(); j++){
    //        if(parentNodes.at(j) == listEdge.at(i)->pal){
    //            adderpal = false;
    //            break;
    //        }
    //    }

    //    for(int j = 0; j < parentNodes.size(); j++){
    //        if(parentNodes.at(j) == listEdge.at(i)->person){
    //            adderper = false;
    //            break;
    //        }
    //    }

    //    if(adderpal == false && adderper == false){
    //        adder = false;
    //    }

    //    if(adder){
    //        treeEdges.push_back(listEdge.at(i));
    //    }

    //    if(adderpal == false && adderper == true){
    //        parentNodes.push_back(listEdge.at(i)->person);
    //    }

    //    if(adderper == false && adderpal == true){
    //        parentNodes.push_back(listEdge.at(i)->pal);
    //    }

    //    if(adderper && adderpal){
    //        parentNodes.push_back(listEdge.at(i)->pal);
    //    }

    //}

    //SECOND ATTEMPT
    //Okay attempt... worked for simple graph but not more complex graphs...

    //for(int i = 0; i < listEdge.size(); i++){
    //    bool adder = true;
        //for(int j = 0; j < treeNodes.size(); j++){
        //    if(treeNodes.at(j) == listEdge.at(i)->person){
        //        for(int k = 0; k < treeNodes.size(); k++){
        //            if(treeNodes.at(k) == listEdge.at(i)->pal){
        //                adder = false;
        //                break;
        //            }
        //       }
        //    }
        //}

        //if(adder){
        //    treeEdges.push_back(listEdge.at(i));
        //    treeNodes.push_back(listEdge.at(i)->person);
        //    treeNodes.push_back(listEdge.at(i)->pal);
        //}
    //}

    //FIRST ATTEMPT
    //Just me testing out stuff... Did not expect it to work and it did not work lol

    //bool checker = false;

    //for(int i = 0; i < treeEdges.size() - 1; i++){
    //    for(int j = 0; j < treeEdges.size() - i - 1; j++){
    //        if(treeEdges[j]->pal != treeEdges[j+1]->person){
    //            Edge * hold = treeEdges[j];
    //            treeEdges[j] = treeEdges[j+1];
    //            treeEdges[j+1] = hold;
    //            checker = true;
    //        }
    //    }

    //    if(checker == false){
    //        break;
    //    }
    //}

    //for(int i = 0; i < treeEdges.size(); i++){
    //    if(i == 0){
    //        tree += treeEdges.at(i)->person->name;
    //    } else if(i == treeEdges.size() - 1) {
    //        tree += "-->" + treeEdges.at(i)->pal->name;
    //    } else{
    //        tree += "-->" + treeEdges.at(i)->pal->name;
    //    }
    //}
    
    int totalLevel = 0;
    for(int i = 0; i < treeEdges.size(); i++){
        tree += treeEdges.at(i)->person->name + "  " + std::to_string(treeEdges.at(i)->level) + "  " + treeEdges.at(i)->pal->name + "\n";
        totalLevel += treeEdges.at(i)->level;
    }

    tree += "Total: " + std::to_string(totalLevel);

    return tree;

}

// Start of private functions
// Finds the node with name, return pointer to that node
GraphNode *Graph::findNodeHelper(string name) { //O(n) where n is length of total nodes
    for(int i = 0; i < this->nodes.size(); i++){
        if (this->nodes.at(i)->name == name){
            return this->nodes.at(i);
        }
    }

    return nullptr;

}

// Finds the edge with named person and pal, return pointer to that edge
Edge *Graph::findEdgeHelper(string person, string pal) { //O(n*m) <- check this one
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

