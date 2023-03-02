#pragma once 

#include <string>
#include <vector>

using std::string;
using std::vector;

class HashTable {
    public:
        HashTable();
        HashTable(int);

        void insert(string value);
        string search(string value);
        bool remove(string value);
        int hash(string value);

    private:
        vector<string> table;
};