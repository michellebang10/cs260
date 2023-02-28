#include <iostream>

#include "binary_node.h"
#include "binary_tree.cpp"

using std::cout;
using std::endl;

int main(){
    //Notes:
    //& address of object
    //* pointer of object

    Binary_node *root_null = nullptr;

    cout << "test 1: empty tree" << endl;

    cout << "doing the main three traversals on an empty tree...  nothing should be printed" << endl;

    in_order_traversal(root_null);

    pre_order_traversal(root_null);

    post_order_traversal(root_null);

    cout << "removing from empty tree" << endl;

    remove_node(root_null, 5, root_null);

    cout << "adding to an empty tree" << endl;

    //this new node becomes the root of the previously empty tree.

    root_null = insert_node(root_null, 43); 

    in_order_traversal(root_null);

    cout << "test 2: non-empty tree" << endl;

    Binary_node *root = new Binary_node{42, nullptr, nullptr};
    Binary_node *left = new Binary_node{21, nullptr, nullptr};
    Binary_node *right = new Binary_node{63, nullptr, nullptr};

    root->left = left;
    root->right = right;

    cout << "new original tree: in-order traversal" << endl;

    in_order_traversal(root);

    cout << "new original tree: pre-order traversal" << endl;

    pre_order_traversal(root);

    cout << "new original tree: post-order traversal" << endl;

    post_order_traversal(root);

    insert_node(root, 5);

    cout << "tree with 5 added at very left" << endl;

    in_order_traversal(root);

    remove_node(root, 5, root);

    cout << "tree with 5 removed" << endl;

    in_order_traversal(root);

    insert_node(root, 5);

    cout << "tree with 5 added again" << endl;

    in_order_traversal(root);

    remove_node(root, 21, root);

    cout << "tree with 21 removed" << endl;

    in_order_traversal(root);

    return 0; 
}