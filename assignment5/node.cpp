#include <iostream>

struct Node {
    int value;
    Node *next;

    Node() {}
    Node(int new_value, Node *new_next) {
        this->value = new_value;
        this->next = new_next;
    }
};