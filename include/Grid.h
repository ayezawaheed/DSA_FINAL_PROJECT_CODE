#ifndef GRID_H
#define GRID_H

#include "HashTable.h"
#include <vector>
#include <string>
#include "Stack.h"  // Include the custom Stack class for stack-based operations

using namespace std;

// Class definition for Grid
class Grid {
public:

    // Constructor to set grid size
    Grid(int rows, int cols);

    // Generate a random grid using words from the dictionary
    void generateGrid(const vector<string>& dictionary);

    //Load a grid configuration from a file
    void loadGrid(const string& filename);

    //Print the grid to the console
    void printGrid();

     // Check if a word exists in the grid using a stack
    bool wordExistsWithStack(const string& word);

   // Find all words in the grid that exist in the hash table
    vector<string> findWords(HashTable& hashTable);

private:
     // Check if a word fits in the grid at a position and direction
    bool canPlaceWord(const string& word, int row, int col, int dr, int dc);

     // Place a word in the grid at a position and direction
    void placeWord(const string& word, int row, int col, int dr, int dc);

    int rows, cols;             // Dimensions of the grid
    vector<vector<char>> grid;  // 2D vector representing the grid
    vector<pair<int, int>> directions;  // List of possible directions for word placement
};

#endif // GRID_H
