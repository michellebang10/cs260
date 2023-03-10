#include <iostream>
#include "chain_hash.h"

using std::cout;
using std::endl;

//following this tutorial: https://www.geeksforgeeks.org/c-program-hashing-chaining/ 
//combining with ideas from class code...

ChainHash::ChainHash() : ChainHash(16) { //O(1)... straightforward...
    //table.reserve(16);
    //size = 0;
}

ChainHash::ChainHash(int initial_size) : capacity{initial_size}, collisionCount{0}, insertCount{0}, size{0} {
    //O(1)... straightforward...
    this->capacity = initial_size;
    table = new list<string>[initial_size];
}

//takes a string value, and places that value at the hashed location in our table.
bool ChainHash::insert(string value) { //O(1 + n/m)... n is the total elements in table... m is size of hash table
    //hash to find location in vector
    int position = hash(value);
    bool collision = false;

    if (table[position].empty()){
        collision = false;
    } else {
        collision = true;
        collisionCount++;
    }

    if (position <= capacity){
        table[position].push_back(value);
        size++;
        insertCount++;
    } 

    return collision;
}

string ChainHash::search(string value) { //O(1 + n/m)... n is the total elements in table... m is size of hash table
    //find hash
    int position = hash(value);

    list <string> :: iterator i;
    for (i = table[position].begin(); 
            i != table[position].end(); i++) {
        if (*i == value) {
            break;
        }
    }

    if (i != table[position].end()){
        return value;
    } else{
        return "this value is not in our hash";
    }
}

//remove value from table if it is in the table, return success of removal.
bool ChainHash::remove(string value) { //O(1 + n/m)... n is the total elements in table... m is size of hash table
    //find hash
    int position = hash(value);

    list <string> :: iterator i;
    for (i = table[position].begin(); 
            i != table[position].end(); i++) {
        if (*i == value) {
            break;
        }
    }

    if (i != table[position].end()){
        table[position].erase(i);
        size--;
        return true;
    }

    return false;
}

//rake a string value and returns a hash that represents the position that it would go in this table's vector.
int ChainHash::hash(string value) { //O(k) where k is the lenght of the string
    //position in the alphabet for the hash...
    //walk through string, adding up the poisitonal data of each character
    int result = 0;
    //we assume all lower-case characters
    for(char& curr : value) {
        result += curr - 'a' + 1;
    }
    result %= getCapacity();

    return result;
}

//helper function to fetch current capacity
int ChainHash::getCapacity() {return capacity;} //O(1)
//helper function to fetch current size
int ChainHash::getSize() {return size;} //O(1)
//helper function to fetch current "fullness"
float ChainHash::getFullness() { //O(1)
    int cap = getCapacity();
    float result = 0.0f;
    if(cap != 0) {
        result = (float)size / (float)cap;
    } else {
        result = -1;
    }
    return result;
}

int ChainHash::getInsertCount() {return insertCount;} //O(1)
int ChainHash::getCollisionCount() {return collisionCount;} //O(1)

void ChainHash::showHash() { //O(n) where n is the total number of elements in the table
    for (int i = 0; i < capacity; i++) {
        cout << i;
        for (auto x : table[i]){
            cout << " --> " << x;
        }  
    cout << endl;
  }
}