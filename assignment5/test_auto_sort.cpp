#include <iostream>

#include "auto_sort.cpp"

using std::cout;
using std::endl;

int main() {
    //create list
    Auto_sort *my_auto_sort = new Auto_sort();
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of empty... should print -1
    cout << "my_auto_sort.at(1): " << my_auto_sort->at(1) << endl;

    //add value to empty list
    my_auto_sort->add(1);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of first index
    cout << "my_auto_sort.at(1): " << my_auto_sort->at(1) << endl;
    
    //add one more to end of list
    my_auto_sort->add(5);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of second index... should be 5
    cout << "my_auto_sort.at(2): " << my_auto_sort->at(2) << endl;

    //add one to the middle
    my_auto_sort->add(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of second index... should be 3 now
    cout << "my_auto_sort.at(2): " << my_auto_sort->at(2) << endl;

    //add one to front
    my_auto_sort->add(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of first index... should be 0 now
    cout << "my_auto_sort.at(1): " << my_auto_sort->at(1) << endl;

    //add duplicate to front
    my_auto_sort->add(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of second index... should be 0 now
    cout << "my_auto_sort.at(2): " << my_auto_sort->at(2) << endl;

    //add duplicate to middle
    my_auto_sort->add(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of third index... should be 3 now
    cout << "my_auto_sort.at(3): " << my_auto_sort->at(3) << endl;
    //check position of fourth index... should be 3 now
    cout << "my_auto_sort.at(4): " << my_auto_sort->at(4) << endl;

    //remove from middle of list
    my_auto_sort->remove(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of fourth index... should be 5 now
    cout << "my_auto_sort.at(4): " << my_auto_sort->at(4) << endl;

    //remove from end of list
    my_auto_sort->remove(5);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of fifthindex (does not exists value now)... should be -1 now
    cout << "my_auto_sort.at(5): " << my_auto_sort->at(5) << endl;

    //remove from front of list
    my_auto_sort->remove(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of first index... should be 0 still
    cout << "my_auto_sort.at(1): " << my_auto_sort->at(1) << endl;

    //remove from real front of list
    my_auto_sort->remove(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    //check position of first index... should be 1 now
    cout << "my_auto_sort.at(1): " << my_auto_sort->at(1) << endl;

    //remove all values
    my_auto_sort->remove(1);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    my_auto_sort->remove(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //remove from empty list
    my_auto_sort->remove(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;


    return 0;
};