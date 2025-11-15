#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

//class definition
class HashTable {
public:
    // Constructor to initialize the hash table with a given size
    HashTable(int size);

    // Method to insert a word into the hash table
    void insert(const string& word);

    // Method to search for a word in the hash table
    bool search(const string& word) const;

private:
    // Hash function to compute the index for a given word
    int hashFunction(const string& word) const;

    // Vector of lists to store the hash table
    vector<list<string>> table;
};

#endif
