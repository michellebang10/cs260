#include <iostream>
#include "binary_node.h"

using std::cout;
using std::endl;

void in_order_traversal(Binary_node *current) {
    if(current != nullptr) {
        in_order_traversal(current->left);
        cout << "current->value: " << current->value << endl;
        in_order_traversal(current->right);
    }
}

void pre_order_traversal(Binary_node *current) {
    if(current != nullptr) {
        cout << "current->value: " << current->value << endl;
        pre_order_traversal(current->left);
        pre_order_traversal(current->right);
    }
}

void post_order_traversal(Binary_node *current) {
    if(current != nullptr) {
        post_order_traversal(current->left);
        post_order_traversal(current->right);
        cout << "current->value: " << current->value << endl;
    }
}

void insert_node(Binary_node *root, int value){
    Binary_node *current = root; //idk why this isn't working
    //need help...
    //idea: start at root, if value > root.value, go left, otherwise, go right. do same with next node to compare... keep doing until node->next is null and add there...
    
}

void remove_node(){

}

int main(){
    Binary_node root{42, nullptr, nullptr};
    Binary_node left{21, nullptr, nullptr};
    Binary_node right{63, nullptr, nullptr};

    root.left = &left;
    root.right = &right;

    return 0; 
}