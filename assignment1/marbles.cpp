#include <iostream>


using std::cout;
using std::endl;
using std::string;


int main(void) {

    // Attempt at showing that the bag is empty!
    //int bag[] = {};
    //try {
    //    cout << bag[0];
    //} catch (...) {
    //    cout << "Bag is empty!";
    //}
    //bag[0] = 0;
    //cout << bag[0];
    //return 0;

    // make a bag with five marbles
    int bagfive[5] = {1, 2, 3, 4, 5};

    // check that there is five marbles

    cout << "checking the five marbles" << endl;
    for(int i = 0; i < 5; i++) {
        cout << bagfive[i] << endl;
    }

    // add one marble at the end
    bagfive[5] = 6;

    cout << "checking new marble was added" << endl;
    for(int i = 0; i < 6; i++) {
        cout << bagfive[i] << endl;
    }

    cout << "this marble was added in: ";
    cout << bagfive[5] << endl;

    // removing one marble in the middle (index 3, value 4)

    cout << "this was the marble in index 3 before: ";
    cout << bagfive[3] << endl;

    for(int i = 0; i < 5; i++) {
        if (i < 3) {
            bagfive[i] = bagfive[i];
        } else {
            bagfive[i] = bagfive[i + 1];
        }
    }

    cout << "checking if marble was removed" << endl;
    for(int i = 0; i < 5; i++) {
        cout << bagfive[i] << endl;
    }

    cout << "this is the marble in index 3 now: ";
    cout << bagfive[3] << endl;

}