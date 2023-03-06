#include <iostream>

#include "chain_hash.h"
#include "chain_hash.cpp"

using std::cout;
using std::endl;

int main() {
    ChainHash ht;
    // check initial capacity of default construction of hashTable
    cout << "ht.getCapacity(): " << ht.getCapacity() << endl;

    // test a few hash values
    cout << "hash(\"aaa\"): " << ht.hash("aaa") << endl;
    cout << "hash(\"ace\"): " << ht.hash("ace") << endl;
    cout << "hash(\"joe\"): " << ht.hash("joe") << endl;
    cout << "hash(\"bob\"): " << ht.hash("bob") << endl;

    // insert "aaa" and show we have "aaa" in our table
    ht.insert("aaa");
    cout << "we have: " << ht.search("aaa") << " in our hash" << endl;

    // search for something not in our table
    cout << ht.search("cat") << endl;

    // attempt to remove value not in table
    cout << "remove(\"ab\"): " << (ht.remove("ab") ? "removal succeeded" : "removal failed") << endl;

    // attempt to remove value in table
    cout << "remove(\"aaa\"): " << (ht.remove("aaa") ? "removal succeeded" : "removal failed") << endl;

    // insert some values
    ht.insert("aaa");
    ht.insert("ace");
    ht.insert("joe");
    ht.insert("bob");
    ht.insert("cat");

    cout << "search(\"joe\"): " << "\"" << ht.search("joe") << "\"" << endl;

    // what are size, capacity, and fullness of our good table?
    cout << "ht.getSize(): " << ht.getSize() << endl;
    cout << "ht.getCapacity(): " << ht.getCapacity() << endl;
    cout << "ht.getFullness(): " << ht.getFullness() << endl;

    // insert in value that would "normally" cause collision
    // no collisions do to chaining
    cout << "insert(\"ab\"): " << (ht.insert("ab") ? "insert succeeded" : "insert failed") << endl;
    // and make sure the value was still placed in the table!
    cout << "search(\"ab\"): " << "\"" << ht.search("ab") << "\"" << endl;

    //print table with chaining :D
    ht.showHash();


    return 0;
}