#pragma once 

#include <string>
#include <vector>

using std::string;
using std::vector;

class HashTable {
    public:
        HashTable();
        HashTable(int initial_size);

        bool insert(string value);
        string search(string value);
        bool remove(string value);

        int hash(string value);

        int getCapacity();
        int getSize();
        float getFullness();

        int getInsertCount();
        int getCollisionCount();

        string toString();

    private:
        vector<string> table;
        int size;
        int capacity;

        int insertCount;
        int collisionCount;
};