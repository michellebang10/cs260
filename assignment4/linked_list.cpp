#include <climits>
#include <iostream>

#include "linked_list.h"
#include "node.h"

using std::cout;
using std::endl;

LinkedList::LinkedList() {
    front = nullptr;
    size = 0;
}

int LinkedList::get_size() {return size;}

void LinkedList::add(int new_value, int new_position) {
    //some way to add values into my list inserted one position after the position given
    //create generic node, then specialize it later based on our situation
    Node *new_node = new Node{new_value, nullptr};
    Node *current = front;
    //check for empty
    if(current != nullptr){
        //find where the new node should go
        for(int current_position = 0; current_position < new_position && current->next != nullptr; ++current_position) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    } else {
        front = new_node;
    }

    //are we adding before the front?
    if(new_position < 0){
        new_node->next = front;
        front = new_node;
    }
    ++size;
}

//some way to remove values off of my list
void LinkedList::remove(int old_position) {

    Node *current = front;
   
    if(current != nullptr){
        for(int current_position = 0; current_position < old_position && current->next != nullptr; ++current_position) {
            current = current->next;
        }
        Node *next = current->next;
        delete current->next;
        --size;
    }

    if(old_position < 0){
        cout << "the list is empty, nothing to remove :(" << endl;
    }
    
}

int LinkedList::get(int position) {
    Node *current = front;
    //check for empty
    if(current != nullptr){
        //find where the new node should go
        for(int current_position = 0; current_position < position && current->next != nullptr; ++current_position) {
            // pass
        }
        return current->value;
    } else {
        return current->value;
    }
}

