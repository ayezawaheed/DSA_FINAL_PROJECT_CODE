#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include "HashTable.h"   // Include the HashTable class definition
using namespace std;

// Class definition
class Dictionary {
public:
    // Static function to load dictionary words from a file into a hash table
    // - filename: Name of the file containing dictionary words
    // - hashTable: Reference to a HashTable object where words will be inserted
    static void loadDictionary(const string& filename, HashTable& hashTable);
};

#endif
