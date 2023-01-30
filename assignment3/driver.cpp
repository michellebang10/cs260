#include <iostream>
#include "node.cpp"
#include "queue.cpp"
using std::cout;
using std::endl;


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

