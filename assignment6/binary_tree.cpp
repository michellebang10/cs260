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

Binary_node *insert_node(Binary_node *cur_root, int num){ //log(n).. draw out actual tree... and how many nodes to touch... depth of tree
    Binary_node *current = cur_root;
    Binary_node *future = current;
    if(current != nullptr){
        if (num < current->value){
            // -> when you have a pointer
            // . when you have direct access to object
            current = future;
            future = current->left;
        } else{
            current = future;
            future = current->right;
        }
        //Binary_node *newnode = new Binary_node{value, nullptr, nullptr};
        if(future == nullptr){
            Binary_node *newnode = new Binary_node{num, nullptr, nullptr};
            if (num < current->value){
                current->left = newnode;
            } else{
                current->right = newnode;
            }
            return newnode;
        }
        //return newnode;
    }

    return insert_node(future, num);
}

Binary_node *most_right(Binary_node *cur_root){
    Binary_node *current = cur_root;
    Binary_node *future = cur_root->left;
    while(future->left != nullptr){
        current = future;
        future = future->right;
    }

    return current;
    
}

Binary_node *node_before(Binary_node *cur_root, Binary_node *interest){
    Binary_node *current = cur_root;
    Binary_node *future = current;

    while(future->value != interest->value){
        if(interest->value < current->value){
            current = future;
            future = current->left;
        }else{
            current = future;
            future = current->right;
        }
    }

    return current;
    
}


Binary_node *remove_node(Binary_node *cur_root, int num, Binary_node *parent_node){
    Binary_node *current = cur_root;
    Binary_node *future = current;
    Binary_node *parent = parent_node;

    if(current->value > num){
        current = future;
        future = current->left;
    } else if(current->value < num){
        current = future;
        future = current->right;
    }

    if(current->value == num){
        if(current->left != nullptr){
            Binary_node *replacement_node_before = most_right(current->left);
            Binary_node *replacement_node = replacement_node_before->left;
            replacement_node->left = current->left;
            delete current;
            replacement_node_before->left = nullptr;
            return replacement_node;
        } else{
            Binary_node *before_node = node_before(parent_node, current);
            before_node->left = nullptr;
            delete current;
            return before_node;
        }
    }

    return remove_node(future, num, parent_node);
    
    // Old code
    // if(current->value == num){
    //     if(current->left != nullptr){
    //         Binary_node *replacement_node_before = most_right(current->left);
    //         Binary_node *replacement_node = replacement_node_before->left;
    //         replacement_node->left = current->left;
    //         delete current;
    //         replacement_node_before->left = nullptr;
    //         return replacement_node;
    //     } else{
    //         Binary_node *before_node = node_before(parent_node, current);
    //         before_node->left = nullptr;
    //         delete current;
    //         return before_node;
    //     }
    // } else if(current->value > num){
    //     current = future;
    //     future = current->left;
    // } else{
    //     current = future;
    //     future = current->right;
    // }

    //pre-code notes:
    /*idea: start at root... 
    compare values until get to node with value inputted... 
    figure out way to choose what node to replace value... 
    (ask question)... make new tree w/o value.. delete value..*/
    //log(n)
    //either biggest left or smallest right
    //compare with node that you remove
}

int main(){
    //Notes:
    //& address of object
    //* pointer of object

    Binary_node root{42, nullptr, nullptr};
    Binary_node left{21, nullptr, nullptr};
    Binary_node right{63, nullptr, nullptr};

    root.left = &left;
    root.right = &right;

    insert_node(&root, 5);

    in_order_traversal(&root);

    remove_node(&root, 5, &root);

    in_order_traversal(&root);

    return 0; 
}