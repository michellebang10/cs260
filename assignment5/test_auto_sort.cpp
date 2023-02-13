#include <iostream>

#include "auto_sort.cpp"

using std::cout;
using std::endl;

int main() {
    //create list
    Auto_sort *my_auto_sort = new Auto_sort();
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //add value to empty list
    my_auto_sort->add(1);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;
    
    //add one more to end of list
    my_auto_sort->add(5);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //add one to the middle
    my_auto_sort->add(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //add one to front
    my_auto_sort->add(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //add duplicate to front
    my_auto_sort->add(0);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    //add duplicate to middle
    my_auto_sort->add(3);
    cout << "my_auto_sort.to_string(): " << my_auto_sort->to_string() << endl;

    return 0;
};