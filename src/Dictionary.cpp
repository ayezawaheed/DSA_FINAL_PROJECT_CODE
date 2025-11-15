#include <fstream>
#include <iostream>

#include "Dictionary.h"
using namespace std;

// Function to load words from a file into a hash table
void Dictionary::loadDictionary(const string& filename, HashTable& hashTable) {
  // Open the specified file for reading
  ifstream file(filename);

  // Check if the file could not be opened
  if (!file) {
    cout << "Error: Cannot open dictionary file.\n";  // Print error message
    return;  // Exit the function if the file cannot be opened
  }

  string word;  // Temporary variable to hold each word read from the file

  // Read words from the file one by one
  while (file >> word) {
    // Insert each word into the hash table
    hashTable.insert(word);
  }
}
