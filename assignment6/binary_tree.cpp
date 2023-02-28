#include <iostream>
#include "binary_node.h"

using std::cout;
using std::endl;

void in_order_traversal(Binary_node *current) {
    //function that prints out in-order traversal of tree.
    //O(n)... prints out all the nodes in tree.

    if(current != nullptr) {
        in_order_traversal(current->left);
        cout << "current->value: " << current->value << endl;
        in_order_traversal(current->right);
    }
}

void pre_order_traversal(Binary_node *current) {
    //function that prints out pre-order traversal of tree. 
    //O(n)... prints out all the nodes in tree.

    if(current != nullptr) {
        cout << "current->value: " << current->value << endl;
        pre_order_traversal(current->left);
        pre_order_traversal(current->right);
    }
}

void post_order_traversal(Binary_node *current) {
    //function that prints out post-order traversal of tree.
    //O(n)... prints out all nodes in tree.  

    if(current != nullptr) {
        post_order_traversal(current->left);
        post_order_traversal(current->right);
        cout << "current->value: " << current->value << endl;
    }
}

Binary_node *insert_node(Binary_node *cur_root, int num){ //log(n).. draw out actual tree... and how many nodes to touch... depth of tree
    //function that inserts a node to the end of tree. 
    //O(log(n))... recursive call for half of tree...
    
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
    } else{
        Binary_node *newnode = new Binary_node{num, nullptr, nullptr};
        return newnode;
    }

    return insert_node(future, num);
}

Binary_node *most_right(Binary_node *cur_root){
    //function that finds the largest node to the left.
    //O(log(n))... cutting half of the tree each time (in while loop)

    Binary_node *current = cur_root;
    Binary_node *future = cur_root->left;

    if(future == nullptr){
        return current;
    }

    while(future->left != nullptr){
        current = future;
        future = future->right;
    }

    return current;
    
}

Binary_node *node_before(Binary_node *cur_root, Binary_node *interest){
    //function that finds the node before the one of interest.
    //O(log(n))... recursive call to half of tree..

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
    //function that removes a node from the tree. 
    //O(log(n))...recursive call to half of tree..

    Binary_node *current = cur_root;
    Binary_node *future = current;
    Binary_node *parent = parent_node;

    if(current == nullptr){
        cout << "this is an empty tree!" << endl;
        return current;
    }

    if(current->value > num){
        current = future;
        future = current->left;
    } else if(current->value < num){
        current = future;
        future = current->right;
    }

    if(current->value == num){
        if(current->left != nullptr){
            Binary_node *replacement_node_before = most_right(current);
            Binary_node *replacement_node = replacement_node_before->left;
            if(replacement_node_before == current){
                Binary_node *before_current = node_before(parent, current);
                before_current->left = replacement_node;
                delete current;
                return replacement_node;
            } else{
                replacement_node->left = current->left;
                delete current;
                replacement_node_before->left = nullptr;
                return replacement_node;
            }      
        } else{
            Binary_node *before_node = node_before(parent, current);
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

