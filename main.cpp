#include "GameManager.h"
#include "Grid.h"
#include "Dictionary.h"
#include "HashTable.h"  // Include the HashTable class
#include "Stack.h"      // Include the custom Stack class
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> // For transform()
using namespace std;

int main() {
    // Load dictionary words from a file
    ifstream dictionaryFile("C:\\Users\\HC\\Downloads\\google-10000-english-no-swears (1).txt");

    vector<string> dictionary; // Vector to store dictionary words
    string word; // Temporary variable to hold each word

    // Read all words from the file and store them in the vector
    while (dictionaryFile >> word) {
        dictionary.push_back(word);
    }

    // Create and initialize the grid with a size of 13x13
    Grid grid(13, 13); // Grid object representing the game board
    grid.generateGrid(dictionary); // Generate the grid using the dictionary words

    // Print the generated grid to the console
    cout << "Generated Grid:\n\n";
    grid.printGrid();

    // Load dictionary into a hash table for efficient word validation
    HashTable hashTable(1000);  // Specify the size of the hash table

    Dictionary::loadDictionary("C:\\Users\\HC\\Downloads\\google-10000-english-no-swears (1).txt", hashTable);
    // Prompt the user to enter words found in the grid
    cout << "\nEnter words you find in the grid (type 'exit' to finish):\n";

    int score = 0; // Variable to keep track of the user's score
    vector<string> userWords; // Vector to store words entered by the user

    // Game loop: Accept user input for words
    while (true) {
        cout << "> ";
        cin >> word; // Get word input from the user

        // Convert the input word to lowercase for case-insensitive comparison
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Check if the user wants to exit the game
        if (word == "exit") {
            break;
        }

        // Check if the word has already been entered
        if (find(userWords.begin(), userWords.end(), word) != userWords.end()) {
            cout << "Word already entered!\n";
            continue;
        }

        // Validate the word: check if it exists in the hash table
        if (hashTable.search(word)) {
            // Check if the word exists in the grid using the new stack-based search method
            if (grid.wordExistsWithStack(word)) {
                cout << "Valid word!\n";
                userWords.push_back(word); // Add the word to the list of found words
                score += 5; // Increase score based on word length
            } else {
                cout << "Word not found in the grid!\n";
                score -= 2; // Penalize for an invalid word not found in the grid
            }
        } else {
            cout << "Invalid word!\n";
            score -= 2; // Penalize for an invalid word
        }
    }

    // Display the final score and words found by the user
    cout << "\nFinal Score: " << score << "\n";
    cout << "Words Found: ";
    for (size_t i = 0; i < userWords.size(); ++i) {
    cout << userWords[i] << " ";
}
    cout << "\n";

    return 0;
} // End of main function
