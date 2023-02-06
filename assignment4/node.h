#pragma once

/*
Node class represents a link in a linked list,
    contains a value and a pointer to the next Node in the list.
This is from class code!!
*/

struct Node {
    int value;
    Node *next;

    Node() {}
    Node(int new_value, Node *new_next) {
        this->value = new_value;
        this->next = new_next;
    }
};