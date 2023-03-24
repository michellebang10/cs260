#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;

struct GraphNode { //Simple node struct that creates a "person".
    string name; //Name of person/friend.
    vector<Edge *> friendshipLevel; //People are connected by friendship levels :3
    vector<GraphNode *> friendship; //Collecting all the friendships you have :3

    string toString() { //O(n) is the number of friends (because you have one friendship which each friend)
        string result = "";

        result += this->name + "[Friends: "; //Get name of node.
        for(auto edge: this->friendshipLevel){ //For all its edge/friendships...
            result += edge->pal->name + ": " + std::to_string(edge->level) + ", "; //Get the name of its pal and their friendship level.
        }
        result += "]";

        //First Attempt:
        //result += this->name + " [Friends: ";
        //for(auto neighbor: this->friendship) { //All the name
        //    result += neighbor->name + ", ";
        //}
        //result += "] [Friendship Levels: ";
        //for(auto edge: this->friendshipLevel) { 
        //    result += std::to_string(edge->level) + ", ";
        //}
        //result += "]";
    
        return result;
    }
};