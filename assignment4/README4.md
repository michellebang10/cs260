1) Add function: 
    -get specific position of list
    -add new node to that position
    -have the node before that position now point to the new node
    -have the new node point to the old node at the position

    from linked_list.cpp:

void LinkedList::add(int new_value, int new_position) { 
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

2) Remove function:
    -get specific position of list
    -store info about that node
    -have the pointer before that point to the pointer after that node
    -delete the old node

    from linked_list.cpp:

void LinkedList::remove(int old_position) {

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

3) Get function
    -get specific position of list
    -get value of that position

    from linked_list.cpp:

int LinkedList::get(int position) {

    Node *current = front;
  
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

For test, look at linkedlistdriver.cpp!!

Thanks to: lecture videos from spring 2022 and the OSU CS tutoring...