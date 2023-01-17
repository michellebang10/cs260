#include <iostream>


using std::cout;
using std::endl;
using std::string;



int main(void) {

    // First attempt at showing that the bag is empty!
    int bagemp[] = {};
    // try {
    //   cout << bagemp[0];
    //} catch (...) {
    //   cout << "bag is empty!";
    //}
    //bagemp[0] = 0;
    //cout << bagemp[0];
    //return 0;

    // checking that bag is empty
    if (bagemp[0] == NULL){
        cout << "bag is empty!" << endl;
    }
    // the above should be printed out
   
    // adding element to array
    // seeing if element is added
    bagemp[0] = 0;
    cout << "seeing if 0 was added to array" << endl;
    cout << bagemp[0] << endl;
    // 0 should be printed out

    // make a bag with five marbles
    int bagfive[5] = {1, 2, 3, 4, 5};

    // check that there is five marbles

    cout << "checking the five marbles" << endl;
    int n = sizeof(bagfive) / sizeof(int);
    cout << "the array has a length of size: ";
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        cout << bagfive[i] << endl;
    }
    // 1, 2, 3, 4, 5 should be printed out in separate lines

    // add one marble at the end
    bagfive[5] = 6;
    int n_new = sizeof(bagfive) / sizeof(int);
    cout << "the new array has a length of size: ";
    cout << n_new << endl;

    cout << "checking new marble was added" << endl;
    for(int i = 0; i < n_new; i++) {
        cout << bagfive[i] << endl;
    }
    //  1, 2, 3, 4, 5, 6 should be printed out in separate lines

    cout << "this marble was added in: ";
    cout << bagfive[5] << endl;

    // removing one marble in the middle (index 3, value 4)

    cout << "this was the marble in index 3 before: ";
    cout << bagfive[3] << endl;
    // 4 should be printed out

    for(int i = 0; i < 5; i++) {
        if (i < 3) {
            bagfive[i] = bagfive[i];
        } else {
            bagfive[i] = bagfive[i + 1];
        }
    }

    bagfive[5] = NULL;

    int n_new_new = sizeof(bagfive) / sizeof(int);
    cout << "length of new array with 1 element removed: ";
    cout << n_new_new << endl;

    cout << "checking if marble was removed" << endl;
    for(int i = 0; i < n_new_new; i++) {
        cout << bagfive[i] << endl;
    }
    // 1, 2, 3, 5, 6 should be printed out

    cout << "this is the marble in index 3 now: ";
    cout << bagfive[3] << endl;
    // 5 should be printed out

    // keep removing the elements in bagfive until empty

    for(int i = 0; i < n_new_new; i++) {
        bagfive[i] = NULL;
    }

    // checking that bag is empty
    if (bagemp[0] == NULL){
        cout << "bag is empty!" << endl;
    }
    // the above should be printed out

}