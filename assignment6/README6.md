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

    in binary_tree.cpp:

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


    3. a remove function that finds and removes a value and then picks an appropriate replacement node(successor is a term often used for this)

    from binary_tree.cpp:

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

}



    4. we have at least one tree traversal function (I recommend starting with an in-order traversal!) Bonus if you implement the three common traversals (pre-order, post-order, in-order) More Bonus if you also include a breadth-first traversal (sometimes called a level-order search)

    I have all three common ones!!

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

3. Analyze and compare the complexity of insert and search as compared to a binary tree without any order in its nodes.

For a binary tree with no order to its nodes, all of the functions (3 common traversals, add and remove nodes), would be O(n) complexity. Since there is no order, you would have to check all the nodes in order to perform to either add a node or to remove a node. Traversals have to touch/print out all the nodes. In comparison, the complexity of an add and remove function of an ordered binary tree would be O(log(n)) as there is a recursive call for half of the tree--cutting the tree each time in half during the recursive call. The traversal functions would still be O(n) as all the nodes are touched/printed. 


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

tree with 70 added to very right..

current->value: 5

current->value: 42

current->value: 63

current->value: 70


Note: I think I understand pointers a lot better than before!!! I think I'd still need to work on it more to be completely confident, but I have a much better idea on it compared to the beginning of the quarter. For future projects, I think I want to work on better organizing my code (for instance, during tests). 