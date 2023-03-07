#include <iostream>
//#include <sstream> could use this instead of std::to_string on int to convert int to string

#include "hash_table.h"

HashTable::HashTable() : HashTable(16) { //O(1)... straightforward...
    //table.reserve(16);
    //size = 0;
}

HashTable::HashTable(int initial_size) : capacity{initial_size}, collisionCount{0}, insertCount{0}, size{0} {
    table.reserve(initial_size);
    for(int i = 0; i < initial_size; ++i) { //O(k) where k is the initial size
        table.push_back(""); // could use iota to use iterators to fill in those valuies instead...
    }
    //size = 0; // this could also be done with a "member initialization list", which can do references with parens ( ) or values with braces { }
    //capacity = initial_size;
}

//takes a string value, and places that value at the hashed location in our table, return if placement causes a collision.
bool HashTable::insert(string value) { //O(1)... go to specific position...
    //hash to find location in vector
    int candidate_position = hash(value);
    //detect if a collision is about to occur, assume no collision, set collision variable if one is detected
    bool collision = false;
    //a collision is when the value in the table is not my proposed value and the position in the table is not empty (whatever empty means)
    //std::cout << "table.at(" << candidate_position << "): " << "\"" << table.at(candidate_position) << "\"" << std::endl; //debug statement
    if(table.at(candidate_position) != value && table.at(candidate_position) != "") {
        collision = true;
        collisionCount++;
    }

    //place in vector
    table.at(candidate_position) = value;

    //update size variable if no collision has happened
    if(collision == false) {
        size++;
    }

    insertCount++;

    //return if placement causes a collision
    return collision;
}

string HashTable::search(string value) { //O(1)... go to specific position...
    //hash the value to find the position to check in the table and return the value found...
    //we might want to switch this to be a boolean representing whether or not the value passed in matches the value in the table where the value would be found...
    return table.at(hash(value));
}

//remove value from table if it is in the table, return success of removal.
bool HashTable::remove(string value) { //O(1)... go to specific position...
    //find hash
    int candidate_position = hash(value);
    //check if value in table is the same as our proposed value and empty if so, do not empty otherwise!
    if(table.at(candidate_position) == value) {
        //remove value from table
        table.at(candidate_position) = "";
        //update size!
        size--;
        return true;
    }

    return false;
}

//rake a string value and returns a hash that represents the position that it would go in this table's vector.
int HashTable::hash(string value) { //O(k) where k is the length of the string
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
int HashTable::getCapacity() {return capacity;} //O(1)
//helper function to fetch current size
int HashTable::getSize() {return size;} //O(1)
//helper function to fetch current "fullness"
float HashTable::getFullness() { //O(1)... straightforward function
    int cap = getCapacity();
    float result = 0.0f;
    if(cap != 0) {
        result = (float)size / (float)cap;
    } else {
        result = -1;
    }
    return result;
}

int HashTable::getInsertCount() {return insertCount;} //O(1)
int HashTable::getCollisionCount() {return collisionCount;} //O(1)

string HashTable::toString() { //O(n) where n is the total number of elements in the table.
    string result = "[";

    for(int key = 0; key < getCapacity(); ++key) {
        if(table.at(key) != "") {
            result += "(" + std::to_string(key) + ", " + table.at(key) + ")";
        }
    }

    result += "]";

    return result;
}