//top
//bottom
//dequeue: remove element from front and return its value
//enqueue: add value to back of queue
//peek: returns the value at the front without removing it

#include <iostream>
#include "node.cpp"
using std::cout;
using std::endl;

Node *enqueue(int new_value, Node *back) { // O(1) no matter what the input, the run time is the same.
// add value to the back of queue
    Node *new_node = new Node(new_value, nullptr);

    if (back != nullptr){
        back->next = new_node;
    }

    return new_node;
}

Node *dequeue(Node *front){ // O(1) no matter what the input, the run time is the same.
    // remove element from front and returns its value
    if(front == nullptr) {
     return nullptr;
    }

    // grab onto next value
    Node *next = front->next;
    // remove front
    delete front;
    // return address of next value
    return next;
}

int peek(Node *top) { // O(1) no matter what the input, the run time is the same.
    // function that takes the value of the first element without removing it
    return top->value;
}







