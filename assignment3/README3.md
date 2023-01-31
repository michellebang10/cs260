Assignment 3 (Linked Queue)

Refer to my assignment 2 README for design: https://github.com/michellebang10/cs260/blob/main/assignment2/README2.md 

1) Uses a linked-list structure:
(in node.cpp)

class Node {
    public:
        int value;
        Node *next;

    Node() {}
    Node(int new_value, Node *new_next){
        this->value = new_value;
        this->next = new_next;
    }

};

2) Enqueue:

Function: (I WILL USE A CLASS NEXT TIME!!)
(in queue.cpp)

Node *enqueue(int new_value, Node *back) { // O(1) no matter what the input, the run time is the same.
// add value to the back of queue
    Node *new_node = new Node(new_value, nullptr);

    if (back != nullptr){
        back->next = new_node;
    }

    return new_node;
}

Test:
(in driver.cpp)

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

3) Dequeue:

Function:
(in queue.cpp)

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

Test:
(in driver.cpp)

 //should print 10 
    cout << "head_ptr->value: " << head_ptr->value << endl;

    // removing the top value of queue (dequeue)
    head_ptr = dequeue(head_ptr); 

    cout << "dequeue is working! first time!" << endl;

    //should print 12
    cout << "head_ptr->value: " << head_ptr->value << endl;

    // removing the top value of queue (dequeue)
    head_ptr = dequeue(head_ptr); 

    cout << "dequeue is working! second time!" << endl;

    //should print 11
    cout << "head_ptr->value: " << head_ptr->value << endl;

4) Peek:

Function:
(in queue.cpp)

int peek(Node *top) { // O(1) no matter what the input, the run time is the same.
    // function that takes the value of the first element without removing it
    return top->value;
}

Test: 
(in driver.cpp)

// should print 10
    //cout << "top.value: " << top.value << endl;
    cout << "head_ptr->value:  " << head_ptr->value << endl;

    // should print 10
    cout << "peek(head_ptr): " << peek(head_ptr) << endl;

REFLECTION ON THIS ASSIGNMENT
-I have understood why I should use classes for my loose functions...Loose functions do make things more complicated..
-C++ and pointers are important but difficult concepts to learn for the first time :')



