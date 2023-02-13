/*
following class code from winter 2022 :D!
*/

#include <string>
#include "node.cpp"

using std::string;

class Auto_sort {
    private:
        Node *front;

        Node *find_previous_node(int value) {
            Node *future = front->next;
            Node *current = front;
            while(future != nullptr && value > future->value) {
                current = future;
                future = future->next;
            }

            return current;
        }

    public:

        //constructor member function
        Auto_sort(){
            front = nullptr; 
        }

        //add a new value at appropriate value
        void add(int new_value) {
            //insert when empty?
            if(front == nullptr){
               Node *new_node = new Node(new_value, nullptr);
               front = new_node;
            } else if (new_value < front->value) {
                //insert before front
                Node *new_node = new Node(new_value, front);
                front = new_node;
            } else{
                //insert in middle
                //Node *future = front->next;
                //Node *current = front;
                //while(future != nullptr && new_value < future->value) {
                    //current = future;
                    //future = future->next;
                //}
                //now insert the value!
                //Node *new_node = new Node(new_value, future);
                //current->next = new_node;


                Node *previous = find_previous_node(new_value);
                Node *new_node = new Node(new_value, previous->next);
                previous->next = new_node;
            }
        }

        //remove the first instance of a given value
        int remove(int old_value){
            int current_value = -1;

            if(front == nullptr){
                current_value = -2;
            } else if(front->value == old_value){
                Node *current = front;
                current_value = current->value;
                front = front->next;
                delete current;
            } else{
                Node *previous = find_previous_node(old_value);
                Node *current = previous->next;
                int current_value = current->value;

                previous->next = current->next;
                delete current;

                //previous->next = future;
                //delete current;

                
            }

            return current_value;   
        }

        //fetch the value stored at index
        int at(int position){
            // same code from assignment 4... did myself :D!
            Node *current = front;
            //check for empty
            if(current != nullptr){ //O(n) going through a straight path....
            //find where the new node should go
            for(int current_position = 0; current_position < position && current->next != nullptr; ++current_position) {
                current = current->next;
            }
            return current->value;
        } else {
            return -1;
        }
        }

        string to_string() {
            string result = "";

            Node *current = front;
            while(current != nullptr){
                result = result + std::to_string(current->value) + ", ";
                current = current->next;
            }

            return result;
        }

};