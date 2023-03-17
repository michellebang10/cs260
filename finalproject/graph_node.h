#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;

struct GraphNode {
    string name; // name of person/friend
    vector<Edge *> friendshipLevel; // people are connected by friendship levels :3
    vector<GraphNode *> friendship; // collecting all the friendships you have :3

    string toString() {
        string result = "";
        result += this->name + " (";
        for(auto neighbor: this->friendship) {
            result += neighbor->name + ", ";
        }
        result += ")";

        return result;
    }
};