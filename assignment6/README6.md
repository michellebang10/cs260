1. Create some tests (at least one per function) that you want your Binary Search Tree (BST) to pass before you start coding.

Assume that left side is always less than previous node and right side is always greater than previous node... 

Add Function Test: Check that node is in correct position by starting at root of tree and printing every value until the newly added node. Use a combination of either in-order and post-order or in-order and pre-order traversals to figure out the shape of the tree. We can then see if the printed values match our rules of left and right. 

Remove Function Test: Print out the whole tree and check if given node was removed. Use a combination of either in-order and post-order or in-order and pre-order traversals to figure out the actual shape of the tree. We can then see if the printed values match our rules of left and right. 

Tree Traversal Function Test: We can draw out our expected tree and its printed values. We then can compare those values and see if they match up with the transversal function. 

How the test 2 tree looks like:
        42
    21      63

expected in-order: 21, 42, 63
expected pre-order: 42, 21, 63
expected post-order: 21, 63, 42

2. Implement a binary search tree that includes:

    1. nodes to store values,

    in binary_node.h: 

    struct Binary_node {
    int value;
    Binary_node *left;
    Binary_node *right;
    };

    2. an add function that adds a new value in the appropriate location based on our ordering rules, (I likely used less than or equal to going to the left and greater than values going to the right)

    in

    3. a remove function that finds and removes a value and then picks an appropriate replacement node(successor is a term often used for this)

    4. we have at least one tree traversal function (I recommend starting with an in-order traversal!) Bonus if you implement the three common traversals (pre-order, post-order, in-order) More Bonus if you also include a breadth-first traversal (sometimes called a level-order search)


From test_binary_tree.cpp
Test Outputs:
test 1: empty tree
doing the main three traversals on an empty tree...  nothing should be printed
removing from empty tree
this is an empty tree!
adding to an empty tree
current->value: 43
test 2: non-empty tree
new original tree: in-order traversal
current->value: 21
current->value: 42
current->value: 63
new original tree: pre-order traversal
current->value: 42
current->value: 21
current->value: 63
new original tree: post-order traversal
current->value: 21
current->value: 63
current->value: 42
tree with 5 added at very left
current->value: 5
current->value: 21
current->value: 42
current->value: 63
tree with 5 removed
current->value: 21
current->value: 42
current->value: 63
tree with 5 added again
current->value: 5
current->value: 21
current->value: 42
current->value: 63
tree with 21 removed
current->value: 5
current->value: 42
current->value: 63