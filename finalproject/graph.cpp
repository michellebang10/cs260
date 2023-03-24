#include "graph.h"
#include "edge.h"
#include <string>
using std::string;

// Add a node using name, returns the node added
GraphNode * Graph::addNode(string name) { //O(1)... just making a new node...
    GraphNode * new_node = new GraphNode{name, vector<Edge *>(), vector<GraphNode *>()}; //Create new node with name.

    this->nodes.push_back(new_node); //Add to vector of nodes of graph.

    return new_node; //Return new node.
}

// Add an edge using person and pal as names of nodes to connect
Edge * Graph::addEdge(GraphNode *person, GraphNode *pal, int level) { //O(1)... just adding a new edge...
    Edge * new_edge = new Edge{person, pal, level}; //Create edge.
    Edge * new_edge2 = new Edge{pal, person, level}; //Creating another edge so it goes both ways.

    this->edges.push_back(new_edge); //Pushing back only one of the edges to keep count in the vector of edges of graph.

    person->friendshipLevel.push_back(new_edge); //Pushing back first edge to first node.
    pal->friendshipLevel.push_back(new_edge2); //Pushing back second edge to second node.

    person->friendship.push_back(pal); //Adding second node to the vector of connected nodes of first. 
    pal->friendship.push_back(person); //Adding first node to the vector of connected nodes of second.

    return new_edge; //Return new edge.
}

// Remove a node if it exists, returns true if a node is removed, false otherwise
// NOT REQUIRED: WILL DO IF I HAVE TIME
// Unfortunately, I am very burnt out after spending hours on the MST :"((

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
// Unfortunately, I am very burnt out after spending hours on the MST :"((

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
bool Graph::nodeExists(string name) { //O(n) where n is the number of nodes in the graph. Checking through all the nodes to see if node in question exists.
    //Use find node helper to see if node exists in the graph.
    GraphNode * check = findNodeHelper(name); //Returns either the node or the nullptr if it doesn't exist.
    
    if (check != nullptr){ //If the node retrieved is not the nullptr, return true.
        return true;
    }
    return false; //If the node retrieved is the nullptr, return false. 
}

// Check if an edge exists with the given name, returns true if edge exists, false otherwise...
bool Graph::edgeExists(string person, string pal) {
    //Use find edge helper to see if edge exists in the graph. 
    Edge * check = findEdgeHelper(person, pal); //Returns either the edge or the nullptr if the it doesn't exist.

    if (check != nullptr){ //If the edge retrieved is not the nullptr, return true.
        return true;
    }
    return false; //If the edge retrieved is the nullptr, return false. 
}

string Graph::toString() { //O(n+m) where n is the number of nodes and m is the number of edges. We're just printing out every edge and node in our graph.
    string result = ""; //This code is a variation of the code in one of the lecture videos. 
    for(int i = 0; i < this->nodes.size(); i++) { //For all the nodes in our graph...
        result += this->nodes.at(i)->toString() + "\n"; //Print out the name of the node and its edges!
    }

    return result; //Return the string of nodes and edges...
}

// Find shortest path from node with name to each other node that can be reached, returns a string with that information
string Graph::shortestPath(string name) { //O(n+m) where n is the number of nodes and m is the number of edges. We are going through all the nodes and edges of our graph...
    string path = "node     dist    parent\n";

    GraphNode * person = findNodeHelper(name); //Grab node with the name in question/

    if(person == nullptr){ //If node with such name does not exist...
        return "This node does not exist."; //Return that this node does not exist.
    }

    vector<GraphNode *> listNodes; //Vector of nodes that are checked.
    vector<GraphNode *> queue; //Vector of nodes that are to be checked.
    vector<GraphNode *> parent; //Vector of nodes that are the parent of the nodes checked (indexing should refer to the same node as listNodes).
    vector<int> distances; //Vector of integers that refer to the distance it takes to get from the node in question to other nodes in the graph.
    
    listNodes.push_back(person); //First node is the node in question.
    distances.push_back(0); //First node to first node is distance 0 (same node).

    for(int i = 1; i < this->nodes.size(); i++){ //For the rest of the nodes, push back temporary distance of 100000 (just any big number).
        distances.push_back(100000);
    }

    for(int i = 0; i < this->nodes.size(); i++){ //For the rest of the parent nodes, push back temporary parent node of nullptr.
        parent.push_back(nullptr);
    }

    GraphNode * current = person; //Set current node to the node in question.

    bool checker = true; //Create a boolean checker.

    if(current->friendship.size() == 0){ //If the current node has no friends (aka other connecting nodes)...
        checker = false; //Set checker to false.
    }

    int counter = 0; //Create a counter
    for(int i = 0; i < this->nodes.size(); i++){ //Keeping track of all nodes that have no friends (aka isolated nodes)
        if(this->nodes.at(i)->friendship.size() == 0){
            counter += 1; //For each isolated node, the counter goes up by 1. 
        }
    }

    while (checker){ //While the checker is true... initially it is true as long as the first current has friends...
        for(int i = 0; i < current->friendship.size(); i++){ //Push back all the friends the current has to the queue.
            queue.push_back(current->friendship.at(i)); //These are all the nodes to be checked for now...
        }

        for(int m = 0; m < queue.size(); m++){ //Going through the queue...
            bool check = true; //Create a boolean check.
            for(int n = 0; n < listNodes.size(); n++){ //For the size of the listNodes (the nodes that were already checked)..
                if(listNodes[n] == queue[m]){ //If the node in the queue is already in the listNodes...
                    check = false; //Check is now false and we break the loop.
                    break;
                }
            }
            if(check){ //If check is true... aka if the queue node was not checked before (not in listNodes)...
                listNodes.push_back(queue[m]); //Add the node from the queue to the listNodes...
            }
        }

        for(int z = 0; z < queue.size(); z++){ //For the size of the queue..
            auto it = find(listNodes.begin(), listNodes.end(), queue[z]); //Check where the queue is from the list of nodes.
            int index = it - listNodes.begin(); //Retrieve that index...
            Edge * edge = findEdgeHelper(current->name, queue[z]->name); //Take the edge between current and node in queue..
            auto it2 = find(listNodes.begin(), listNodes.end(), current); //Check where the current is from the list of nodes.
            int i2 = it2 - listNodes.begin(); //Retrieve that index.
            int totEdge = edge->level + distances[i2]; //Total edge is the level of the edge between current and queue node plus the distance of the current.
            if (totEdge < distances[index]){ //If this total edge value is less than the distance that the queue node currently has...
                distances.at(index) = totEdge; //Change the distance of the queue to this totEdge value.
                parent.at(index) = current; //Parent now changes to current.
            }
        }

        auto it2 = find(listNodes.begin(), listNodes.end(), current); //Check where the current is from the list nodes.
        int i2 = it2 - listNodes.begin(); //Retrieve that index.

        current = listNodes.at(i2 + 1); //The new current is now the next node in the list of nodes. 

        if(listNodes.size() == this->nodes.size() - counter){ //If we went through all the nodes that could be checked... (aka non-isolated nodes)
            checker = false; //We are now done, and checker is now false, so the for loop should break. 
        }

        queue.clear(); //Clear the queue.
    }

    for(int i = 0; i < this->nodes.size(); i++){ //We are now trying to add the isolated nodes to listNodes.
        bool check = true; //Create a boolean check.
        for(int n = 0; n < listNodes.size(); n++){
            if(listNodes[n] == this->nodes.at(i)){ //If the node is in listNode...
                check = false; //Check is false..
                break; //Stop checking for this node (this node is from all nodes in graph).
            }
        }
        if(check){ //If check is true (the node is not in listNodes)
            listNodes.push_back(this->nodes.at(i)); //Push that node back into listNodes.
        }
    }

    for(int j = 0; j < this->nodes.size(); j++){ //Creating a string of all the values found...
        if(parent[j] != nullptr){ //If the parent is not nullptr, add to string "normally"...
            path += listNodes[j]->name + "      " + std::to_string(distances[j]) + "      " + parent[j]->name + "\n";
        } else{ //If parent is nullptr, the third column for parent needs to be manually written as "null"..
            if(distances[j] == 100000){ //If the distance is "100000" aka our large placeholder value, change second distance column to "inf"...
                path += listNodes[j]->name + "      " + "inf" + "      " + "null" + "\n";
            } else{ //This is for our "first" node as its parent is nullptr but distance is 0 :)
                path += listNodes[j]->name + "      " + std::to_string(distances[j]) + "      " + "null" + "\n";
            }
        }
    }

    

    return path; //Return the string of the path. 


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
string Graph::minimumSpanningTree() { //O(mlogm) or O(mlogn) or O(m^2) where m is the number of edges and n is the number of nodes (will elaborate in README)
    string tree = "";

    //idea: keep connecting smallest edges together

    vector<Edge *> listEdge; //Vector that stores all the existing vectors in graph.

    if(this->nodes.size() == 0){ //If there are no nodes in the graph...
        return "This is an empty graph."; //Return that this is an empty graph.
    }

    for(int i = 0; i < this->edges.size(); i++){ //Creating a vector of edges from the graph.
        listEdge.push_back(this->edges.at(i)); 
    }

    bool check = false; //Create a boolean false.

    for(int i = 0; i < listEdge.size() - 1; i++){ //Sorting the edges from smallest to largest value.
        for(int j = 0; j < listEdge.size() - i - 1; j++){ //Got help from GeeksForGeeks :3
            if(listEdge[j]->level > listEdge[j+1]->level){ //If the earlier value of vector is greater than the value after it...
                //Switch the ordering of the values. 
                Edge * hold = listEdge[j];
                listEdge[j] = listEdge[j+1]; 
                listEdge[j+1] = hold;
                check = true;
            }
        }

        if(check == false){ //If nothing is to be switched (aka in order), break the loop. 
            break;
        }
    }

    vector<Edge *> treeEdges; //Vector of all the edges included in MST.
    vector<GraphNode *> treeNodes; //Vector of all nodes in graph.
    vector<GraphNode* > parentNodes; //Vector of parent nodes of the nodes in graph (same ordering as treeNodes)
    //vector<GraphNode *> palNodes;
    //vector<GraphNode *> perNodes;


    //SIXTH ATTEMPT
    //ACTUALLY WORKSS!!!! T____T

    for(int i = 0; i < this->nodes.size(); i++){ //For all the existing nodes in graph...
        treeNodes.push_back(nodes.at(i)); //Push back those values to treeNodes.
        parentNodes.push_back(nodes.at(i)); //Push back same value to parentNodes. 
    }

    for(int i = 0; i < listEdge.size(); i++){ //For all the edges in the graph.
        auto it = find(treeNodes.begin(), treeNodes.end(), listEdge.at(i)->person); //Find where first node is in the treeNodes vector.
        int index = it - treeNodes.begin(); //Retrieve that index.
        auto it2 = find(treeNodes.begin(), treeNodes.end(), listEdge.at(i)->pal); //Find where the second node is in the treeNodes vector.
        int index2 = it2 - treeNodes.begin(); //Retrieve that index. 

        if(parentNodes.at(index) != parentNodes.at(index2)){ //If those two nodes don't have the same parent node.
            treeEdges.push_back(listEdge.at(i)); //Add that edge to the MST as it doesn't cause a cycle. 
            GraphNode * oldParent = parentNodes.at(index2); //Hold the current parent of the second node. This is now the old parent.
            for(int n = 0; n < parentNodes.size(); n++){ //For all the parent nodes...
                if(parentNodes.at(n) == oldParent){ //If the parent node at that index is the same as the "old" parent.
                    parentNodes.at(n) = parentNodes.at(index); //Change that parent value to the parent node of the first index.
                }
            }
        }
    }


    //FIFTH ATTEMPT
    //Weird attempt where I kept getting an error...

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
    
    int totalLevel = 0; //Create an integer that holds the total level of the MST.
    for(int i = 0; i < treeEdges.size(); i++){ //For all the edges in the MST...
        //Add the string of the edge information about the two nodes and level to the tree. 
        tree += treeEdges.at(i)->person->name + "  " + std::to_string(treeEdges.at(i)->level) + "  " + treeEdges.at(i)->pal->name + "\n";
        totalLevel += treeEdges.at(i)->level; //Add the level value to total level.
    }

    tree += "Total: " + std::to_string(totalLevel); //Adding the total level at the end of the string.

    return tree; //Return the string of the tree. 

}

// Start of private functions
// Finds the node with name, return pointer to that node
GraphNode *Graph::findNodeHelper(string name) { //O(n) where n is length of total nodes
    for(int i = 0; i < this->nodes.size(); i++){ //For all the existing nodes in the graph...
        if (this->nodes.at(i)->name == name){ //If the inputted "name" is the name of one of the nodes in the graph...
            return this->nodes.at(i); //Return the node with that same name.
        }
    }

    return nullptr; //If the "name" of the graph is not the name of any of the existing nodes, return nullptr.

}

// Finds the edge with named person and pal, return pointer to that edge
Edge *Graph::findEdgeHelper(string person, string pal) { //O(n) where n is the number of nodes as you have to find two nodes that are connected thus O(n+n) = O(n)...
    for(int i = 0; i < this->nodes.size(); i++){ //For all the nodes in the graph...
        if (this->nodes.at(i)->name == person){ //Find the node with the same name as person.
            for (int n = 0; n < this->nodes.at(i)->friendshipLevel.size(); n++){ //For all the friendships that this node has...
                if (this->nodes.at(i)->friendshipLevel.at(n)->pal->name == pal){ //Check they have a friendship with pal.
                    return this->nodes.at(i)->friendshipLevel.at(n); //Then return that friendship/edge.
                }

            }
        }
    }

    return nullptr; //If no such friendship exists, return nullptr. 
}

