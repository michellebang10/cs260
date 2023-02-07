#include <iostream>
#include "node.h"
#include "linked_list.h"
#include "linked_list.cpp"

using std::cout;
using std::endl;

/*
For the general structure of the testing code I followed the example in lecture videos for Spring 2022 :D
*/

int main(int argc, char **argv) {
    LinkedList my_list;

    //check for a newly created list being empty

    cout << "test that a newly created list is empty!" << endl;

    int new_empty_result = my_list.get_size();
    int expected_new_empty_result = 0;
    if(new_empty_result == expected_new_empty_result) {
        cout << "(test passed) new empty test" << endl;
    }
    else {
        cout << "(test failed) new empty test, expected value: " << expected_new_empty_result << ", but instead received: " << new_empty_result << endl;
    }

    //test that our add method works!
    cout << "test that add works!" << endl;
    my_list.add(42, 0);

    int new_add_result = my_list.get_size();
    int expected_new_add_result = 1;

    if(new_add_result == expected_new_add_result) {
        cout << "(test passed) new 1 element test" << endl;
    }
    else {
        cout << "(test failed) new empty test, expected value: " << expected_new_add_result << ", but instead received: " << new_add_result << endl;
    }

    //test that our get works and that the element that is added is 42
    cout << "test that get works and element added was 42!!" << endl;

    if (my_list.get(0) == 42) {
        cout << "(test passed) 42 is in position 0!" << endl;
    } else{
        cout << "(test failed), expected value: 42, but instead received: " << my_list.get(0) << endl;
    }

    //test that remove works
    cout << "test that remove works" << endl;
    //if remove works, then my_list should have size 0
    my_list.remove(0);

    int new_remove_result = my_list.get_size();
    int expected_new_remove_result = 0;
    if(new_remove_result == expected_new_remove_result) {
        cout << "(test passed) the element was removed!" << endl;
    } else {
        cout << "(test failed) the size of the list is supposed to be: " << expected_new_remove_result << ", but instead received: " << new_remove_result << endl;
    } 

    //test removing from empty list
    //-1 should be returned
    int empty_remove_result = my_list.get(0);
    int expected_empty_remove_result = -1;
    if(empty_remove_result == expected_empty_remove_result) {
        cout << "(test passed) removing from empty list!" << endl;
    } else{
        cout << "(test failed) it didn't work D:" << endl;
    }

   //list is empty statement should be printed
    my_list.remove(0);

    return 0;
}
