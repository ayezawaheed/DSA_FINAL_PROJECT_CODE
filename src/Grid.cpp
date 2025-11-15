#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Stack.h"
using namespace std;

// Constructor initializes grid with empty spaces and predefined directions
Grid::Grid(int rows, int cols)
    : rows(rows),
      cols(cols),
      directions({{0, 1},
                  {1, 0},
                  {1, 1},
                  {1, -1},
                  {0, -1},
                  {-1, 0},
                  {-1, -1},
                  {-1, 1}}) {
  // The grid is resized to the specified number of rows and columns and
  // initialized with spaces
  grid.resize(rows, vector<char>(cols, ' '));
}

// Method to check if a word can be placed at a given position and direction
bool Grid::canPlaceWord(const string& word, int row, int col, int dr, int dc) {
  int wordLength = word.size();
  // Loop through each character of the word
  for (int i = 0; i < wordLength; ++i) {
    int newRow = row + i * dr;  // Calculate the row position for the character
    int newCol =
        col + i * dc;  // Calculate the column position for the character

    // Check if position is out of bounds or has a conflicting letter
    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
        (grid[newRow][newCol] != ' ' && grid[newRow][newCol] != word[i])) {
      return false;  // Out of bounds
    }
  }
  return true;
}

// Method to place a word in the grid at a given position and direction
void Grid::placeWord(const string& word, int row, int col, int dr, int dc) {
  int wordLength = word.size();
  // Loop through the characters of the word and place them in the grid
  for (int i = 0; i < wordLength; ++i) {
    grid[row + i * dr][col + i * dc] = word[i];
  }
}

// Method to generate the grid with random words from a dictionary
void Grid::generateGrid(const vector<string>& dictionary) {
  srand(time(0));  // Initialize the random number generator

  // Make a copy of the dictionary and shuffle it to randomize the selection of
  // words
  vector<string> shuffledDictionary = dictionary;
  random_shuffle(shuffledDictionary.begin(), shuffledDictionary.end());

  vector<string> targetWords;
  for (const string& word : shuffledDictionary) {
    // Select words with length between 6 and 7 characters
    if (word.length() >= 6 && word.length() <= 7) {
      targetWords.push_back(word);  // Add word to the target list
    }
    if (targetWords.size() >= 5) {  // Stop after selecting 5 words
      break;
    }
  }

  // Attempt to place the target words into the grid
  int placedWords = 0;
  for (const string& word : targetWords) {
    bool placed = false;
    // Try up to 100 random positions and directions for each word
    for (int attempt = 0; attempt < 100 && !placed; ++attempt) {
      int row = rand() % rows;
      int col = rand() % cols;
      auto [dr, dc] = directions[rand() % directions.size()];

      if (canPlaceWord(word, row, col, dr, dc)) {
        placeWord(word, row, col, dr, dc);
        placed = true;  // Mark the word as placed
        placedWords++;
      }
    }
    // Stop placing words after a maximum of 8 words
    if (placedWords >= 8) {
      break;
    }
  }
  // Fill the remaining empty spaces in the grid with random letters
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (grid[r][c] == ' ') {             // If the cell is empty
        grid[r][c] = 'A' + (rand() % 26);  // Fill it with a random letter
      }
    }
  }
}

// Method to load a grid from a file
void Grid::loadGrid(const string& filename) {
  ifstream file(filename);
  if (!file) {  // Check if the file could be opened
    cerr << "Error: Cannot open grid file.\n";
    return;
  }

  grid.clear();  // Clear the current grid
  string line;
  while (getline(file, line)) {  // Read the file line by line
    vector<char> row(line.begin(),
                     line.end());  // Convert the line to a vector of characters
    grid.push_back(row);           // Add the row to the grid
  }
  // Update the grid's dimensions
  rows = grid.size();
  cols = grid[0].size();
}

// Method to print the grid
void Grid::printGrid() {
  for (const auto& row : grid) {
    for (char cell : row) {
      cout << cell << " ";
    }
    cout << "\n";
  }
}

// Stack-based backtracking to check if a word exists in the grid
bool Grid::wordExistsWithStack(const string& word) {
  int wordLength = word.length();
  Stack rowStack(rows * cols);  // Stack for row indices
  Stack colStack(rows * cols);  // Stack for column indices

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (grid[row][col] ==
          word[0]) {  // Check if the cell matches the first letter
        // Explore all possible directions
        for (const auto& [dr, dc] : directions) {
          int newRow = row;  // Move to the next row
          int newCol = col;  // Move to the next column
          int index = 1;
          // Push the starting position onto the stack
          rowStack.push(newRow);
          colStack.push(newCol);
          // Check the rest of the word in the current direction
          while (index < wordLength) {
            newRow += dr;
            newCol += dc;
            // Break if the next position is invalid or doesn't match
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
                grid[newRow][newCol] != word[index]) {
              break;
            }

            rowStack.push(newRow);  // Push the new position onto the stack
            colStack.push(newCol);
            ++index;
          }

          if (index == wordLength) {  // If the entire word was matched
            return true;
          }

          while (!rowStack.empty()) {
            rowStack.pop();
            colStack.pop();
          }
        }
      }
    }
  }

  return false;  // Word was not found
}

// Find all words in the grid by checking all directions
vector<string> Grid::findWords(HashTable& hashTable) {
  vector<string> foundWords;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      for (const auto& [dr, dc] : directions) {
        string word;
        int x = r, y = c;
        // Build words in the current direction until out of bounds
        while (x >= 0 && x < rows && y >= 0 && y < cols) {
          word += grid[x][y];  // Append the current character to the word
          if (word.size() > 2 &&
              hashTable.search(
                  word)) {  // Check if the word exists in the hash table
            foundWords.push_back(word);  // Add the word to the list
          }
          x += dr;  // Move to the next cell in the direction
          y += dc;
        }
      }
    }
  }

  return foundWords;  // Return the list of found words
}
