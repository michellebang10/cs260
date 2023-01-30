// Following Node class structure taught in class :)!
// Also this page: https://www.geeksforgeeks.org/queue-linked-list-implementation/ 

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