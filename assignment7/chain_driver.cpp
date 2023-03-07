#include <iostream>

#include "chain_hash.h"
#include "chain_hash.cpp"

using std::cout;
using std::endl;

//following this tutorial: https://www.geeksforgeeks.org/c-program-hashing-chaining/ 
//combining with ideas from class code...

int main() {
    ChainHash ht;
    // check initial capacity of default construction of hashTable
    cout << "ht.getCapacity(): " << ht.getCapacity() << endl;

    // test a few hash values
    cout << "hash(\"aaa\"): " << ht.hash("aaa") << endl;
    cout << "hash(\"ace\"): " << ht.hash("ace") << endl;
    cout << "hash(\"joe\"): " << ht.hash("joe") << endl;
    cout << "hash(\"bob\"): " << ht.hash("bob") << endl;

    // insert "aaa" and show we have "aaa" in our table... no collision yet...
    cout << "insert(\"aaa\"): " << (ht.insert("aaa") ? "insert succeeded; collision " : "insert succeeded; no collision") << endl;
    cout << "we have: " << ht.search("aaa") << " in our hash" << endl;

    // search for something not in our table
    cout << ht.search("cat") << endl;

    // attempt to remove value not in table
    cout << "remove(\"ab\"): " << (ht.remove("ab") ? "removal succeeded" : "removal failed") << endl;

    // attempt to remove value that is in table
    cout << "remove(\"aaa\"): " << (ht.remove("aaa") ? "removal succeeded" : "removal failed") << endl;
    // show that value is no longer in table
    ht.search("aaa");

    // insert some values
    ht.insert("aaa");
    ht.insert("ace");
    ht.insert("joe");
    ht.insert("bob");
    ht.insert("cat");

    cout << "search(\"joe\"): " << "\"" << ht.search("joe") << "\"" << endl;

    // insert in value that would cause collision
    cout << "insert(\"ab\"): " << (ht.insert("ab") ? "insert succeeded; collision " : "insert succeeded; no collision") << endl;
    // and make sure the value was still placed in the table!
    cout << "search(\"ab\"): " << "\"" << ht.search("ab") << "\"" << endl;

    // what are size, capacity, and fullness of our good table?
    cout << "ht.getSize(): " << ht.getSize() << endl;
    cout << "ht.getCapacity(): " << ht.getCapacity() << endl;
    cout << "ht.getFullness(): " << ht.getFullness() << endl;

    // how many collsions so far?
    cout << "ht.getCollisionCount(): " << ht.getCollisionCount() << endl;

    //print table with chaining :D
    ht.showHash();

    cout << "\nNumerators on possibly useful statistics:" << endl;
    cout << "\tinsert count: " << ht.getInsertCount() << endl;
    cout << "\tsize: " << ht.getSize() << endl;

    cout << "\nDenominator on possibly useful statistics:" << endl;
    cout << "\tcollision count: " << ht.getCollisionCount() << endl;

    cout << "\nPossibly useful statistics:" << endl;
    cout << "\tsize / collision count: " << (float)ht.getSize() / ht.getCollisionCount() << endl;
    cout << "\tinsert count / collision count: " << (float)ht.getInsertCount() / ht.getCollisionCount() << endl;

    cout << "\nend of program, have a nice day!" << endl;


    return 0;
}