#pragma once

#include <string>
#include <list>

using std::string;
using std::list;

//following this tutorial: https://www.geeksforgeeks.org/c-program-hashing-chaining/ 
//combining with ideas from class code...

class ChainHash {
    list<string> *table;

    public:
        ChainHash();
        ChainHash(int initial_size);

        bool insert(string value);
        string search(string value);
        bool remove(string value);

        int hash(string value);

        int getCapacity();
        int getSize();
        float getFullness();

        int getInsertCount();

        void showHash();

        //string toString();

    private:
        int size;
        int capacity;

        int insertCount;
        int collisionCount;
};