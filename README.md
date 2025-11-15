# Word Search Game with Dynamic Stack and Hash Table

## Overview
This project implements a Word Search Game where users interact with a **grid-based interface** to search for valid words.  
The program generates a randomized grid of letters, loads a dictionary for word validation, and allows users to find words using **stack-based backtracking algorithms**.

### Key Functionalities
1. **Dynamic Grid Creation:** A user-defined grid is generated with random letters and specific words placed strategically.  
2. **Word Validation:** Words are validated using a **hash table** for fast lookup.  
3. **Stack-based Search:** Stack-based backtracking is used to explore all possible word paths.  
4. **User-Friendly Output:** Displays valid words found and supports real-time feedback.  

---

## User Interaction
- A randomized grid is displayed.  
- Users input words they find in the grid to validate them against the dictionary.  
- Results are shown immediately with feedback.  

---

## Data Structures Used

### Hash Table
- **Purpose:** Store and validate dictionary words efficiently.  
- **Structure:** Vector of linked lists with a polynomial hash function.  
- **Role:** Provides O(1) average-time lookup for words.

### Dynamic Stack
- **Purpose:** Track current path during backtracking.  
- **Structure:** Dynamically allocated array supporting push, pop, top.  
- **Role:** Maintains paths during traversal in 8 directions.

### Grid
- **Purpose:** Represents the 2D game grid.  
- **Structure:** 2D array-like structure, supports random word placement.  
- **Role:** Core interface for word search.

---

## Algorithms

### Backtracking Algorithm
1. Input: 2D grid, dictionary hash table, valid directions.  
2. Initialization: Stack for current state, visited matrix.  
3. Procedure: Explore all paths using stack-based backtracking.  
4. Output: List of valid words found in the grid.

### Hash Table Insertion & Search
- **Insertion:** Compute hash index, insert word in linked list.  
- **Search:** Compute hash index, traverse linked list, return true if found.  

### Key Functions
- **canPlaceWord(word, row, col, dr, dc, grid)** – Checks if a word can be placed.  
- **placeWord(word, row, col, dr, dc, grid)** – Places a word in the grid.  
- **generateGrid(dictionary, rows, cols)** – Generates randomized grid with words.  
- **validateUserInput(userInput, grid, hashTable)** – Validates words entered by user.  
- **main()** – Coordinates loading dictionary, grid generation, user input validation, and output.

---

## Requirements
- The game **requires a dictionary file** (text file with words).  
- The dictionary file is **not included** in this repository.  
- Users should provide their own dictionary file and either:  
  - Place it in the same folder as the executable, **or**  
  - Update the file path in `main.cpp` to match the dictionary location.

---

## Development Notes
- File paths in the code are currently hardcoded. To run on another system, update the dictionary file path in `main.cpp` or provide a dictionary in the executable folder.  
- Avoid using spaces in filenames to prevent errors on different systems.

---

## Output
- The program displays a generated grid.  
- Users input words.  
- Valid words found are displayed as output.
