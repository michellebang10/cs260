//top
//bottom
//dequeue: remove element from front and return its value
//enqueue: add value to back of queue
//peek: returns the value at the front without removing it

#include <iostream>
#include "node.cpp"
using std::cout;
using std::endl;

Node *enqueue(int new_value, Node *back) {
// add value to the back of queue
    Node *new_node = new Node(new_value, back);

    return new_node;
}

Node *dequeue(Node *front){
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

int peek(Node *top) {
    // function that takes the value of the first element without removing it
    return top->value;
}


int main(int argc, char **argv) {
    // Node top(10, nullptr);
    // Node bottom(12, nullptr);

    // pointer to node, pointing to top
    // Node *head_ptr = &top;
    Node *head_ptr = enqueue(10, nullptr);
    // point to node, pointing to bottom
    // Node *tail_ptr = &bottom;
    Node *tail_ptr = enqueue(12, nullptr);

    //top.next = &bottom;
    head_ptr->next = tail_ptr;

    // should print 10
    //cout << "top.value: " << top.value << endl;
    cout << "head_ptr->value:  " << head_ptr->value << endl;

    // should print 10
    cout << "peek(head_ptr): " << peek(head_ptr) << endl;

    // showing that top still exists as 10
    //cout << "top.value: " << top.value << endl;
    cout << "head_ptr->value:  " << head_ptr->value << endl;
    
    // should print 12
    //cout << "bottom.value: " << bottom.value << endl;
    cout << "tail_ptr->value:  " << tail_ptr->value << endl;

    cout << "tail_ptr: " << tail_ptr << endl;

    // should print 12
    cout << "tail_ptr.value: " << tail_ptr->value << endl; 

    // adding 11 to the bottom of queue (enqueue)
    tail_ptr = enqueue(11, tail_ptr);

    cout << "tail_ptr: " << tail_ptr << endl;

    // should print 11
    cout << "tail_ptr.value: " << tail_ptr->value << endl;  

    cout << "head_ptr: " << head_ptr << endl;

    //should print 10 
    cout << "head_ptr->value: " << head_ptr->value << endl;

    // removing the top value of queue (dequeue)
    head_ptr = dequeue(head_ptr); 

    cout << "dequeue is working!" << endl;

    //should print 12
    cout << "head_ptr->value: " << head_ptr->value << endl;

}





