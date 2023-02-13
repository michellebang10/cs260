#include <climits>
#include <iostream>

#include "linked_list.h"
#include "node.h"

using std::cout;
using std::endl;

/*
Basic structure is from class code (Spring 2022)...
Got a lot of help from the CS tutoring at OSU :D!!
*/

LinkedList::LinkedList() {
    front = nullptr;
    size = 0;
}

int LinkedList::get_size() {return size;}

void LinkedList::add(int new_value, int new_position) { 
    //some way to add values into my list inserted one position after the position given
    Node *new_node = new Node(new_value, nullptr);
    Node *current = front; 
    //check for empty
    if(current != nullptr){ //O(n) complexity... going through a straight path no matter what...
        //find where the new node should go
        for(int current_position = 0; current_position < new_position && current->next != nullptr; ++current_position) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    } else {
        front = new_node;
    }

    if(new_position < 0){ //O(1)... adding right infront of front.
        new_node->next = front;
        front = new_node;
    }
    ++size;
}


void LinkedList::remove(int old_position) {
    //some way to remove values off of my list

    Node *current = front;
   
    if(current != nullptr){ //O(n) complexity... going through a straight path....
        if(old_position == 0){ 
            front = current->next;
            delete current;
        } else{
            for(int current_position = 0; current_position < old_position && current->next != nullptr; ++current_position) {
            current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete current->next;
        }
        
        --size;
    } else {
        cout << "the list is empty, nothing to remove :(" << endl;
    }
    
}

int LinkedList::get(int position) {
    //some way to look at value at specific position in list

    //Node *current = front;
    //check for empty
    //if(current != nullptr){ //O(n) going through a straight path....
        //find where the new node should go
        //for(int current_position = 0; current_position < position && current->next != nullptr; ++current_position) {
            //current = current->next;
        //}
        //return current->value;
    //} else {
        //return -1;
    //}

    //updated code for get()
    Node *current = front;
    //check for empty
    if(current != nullptr){ //O(n) going through a straight path....
        //find where the new node should go
        int current_position = 0;
        for(;current_position < position && current->next != nullptr; ++current_position) {
            current = current->next;
        }
        if(current_position != position){
            return -1;
        } else{
            return current->value;
        }
        
    } else {
        return -1;
    }
}

