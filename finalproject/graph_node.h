#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;

struct GraphNode {
    string name; // name of person/friend
    vector<Edge *> friendship; // people are connected by friendships :3
};