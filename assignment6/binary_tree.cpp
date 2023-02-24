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
    cout << current->value << endl;
    //need help...
    //idea: start at root, if value > root.value, go left, otherwise, go right. do same with next node to compare... keep doing until node->next is null and add there...

}

void remove_node(Binary_node *root, int value){
    //idea: start at root... compare values until get to node with value inputted... figure out way to choose what node to replace value... (ask question)... make new tree w/o value.. delete value..
}

int main(){
    Binary_node root{421, nullptr, nullptr};
    Binary_node left{21, nullptr, nullptr};
    Binary_node right{63, nullptr, nullptr};

    root.left = &left;
    root.right = &right;

    insert_node(&root, 5);
    //& address of object
    //* pointer of object

    return 0; 
}