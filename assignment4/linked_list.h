#pragma once

#include "node.h"

/*
General idea/outline is from class code!!
*/

class LinkedList {
    private:
        Node *front = nullptr;
        int size = 0;

    public:
        LinkedList();
        int get_size();
        void add(int new_value, int new_position);
        void remove(int old_position);
        int get(int position);
};

