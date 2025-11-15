#include "HashTable.h"
#include <list>
#include <vector>
using namespace std;

// Constructor initializes the hash table with a given size
HashTable::HashTable(int size) : table(size) {}

// Hash function to compute the index for a given word
int HashTable::hashFunction(const string& word) const {
    int hashValue = 0;         // Initialize hash value to zero


    // Compute hash value using a simple polynomial accumulation method
    for (char ch : word) {      // Loop through each character in the word
        hashValue = (hashValue * 31 + ch) % table.size(); // Update hash value and keep it within bounds
    }
    return hashValue;        // Return the computed hash value
}

// Insert a word into the hash table
void HashTable::insert(const string& word) {
    int index = hashFunction(word);       // Get the hash index for the word
    table[index].push_back(word);         // Add the word to the list at the computed index
}

// Search for a word in the hash table
bool HashTable::search(const string& word) const {
    int index = hashFunction(word);       // Get the hash index for the word

    // Traverse the list at the index to check if the word exists
    for (const auto& entry : table[index]) {         //loop through each entry
        if (entry == word) {              // Return true if the word is found
            return true;
        }
    }
    return false;                         // Return false if the word is not found
}
