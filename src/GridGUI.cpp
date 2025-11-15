#include "GridGUI.h"

#include <iostream>
#include <sstream>

GridGUI::GridGUI(int rows, int cols, const std::vector<std::string>& dictionary)
    : rows(rows), cols(cols), dictionary(dictionary), grid(rows, cols) {
    window.create(sf::VideoMode(600, 600), "Word Search Game");
    font.loadFromFile("arial.ttf"); // Ensure you have a valid font file in your project
    selectedWordText.setFont(font);
    selectedWordText.setCharacterSize(24);
    selectedWordText.setFillColor(sf::Color::Black);
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Black);
    gridCell.setSize(sf::Vector2f(50, 50));
    gridCell.setOutlineThickness(1);
    gridCell.setOutlineColor(sf::Color::Black);
}

void GridGUI::drawGrid() {
    window.clear(sf::Color::White);

    // Draw grid cells
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            gridCell.setPosition(j * 50, i * 50);
            window.draw(gridCell);
            // Draw the letter in the cell
            sf::Text letterText;
            letterText.setFont(font);
            letterText.setCharacterSize(24);
            letterText.setString(std::string(1, grid.getCell(i, j))); // Assuming Grid has getCell method
            letterText.setFillColor(sf::Color::Black);
            letterText.setPosition(j * 50 + 15, i * 50 + 10); // Adjust position to center the text
            window.draw(letterText);
        }
    }

    // Draw highlighted cells for the word
    for (const auto& cell : highlightedCells) {
        window.draw(cell);
    }

    // Draw selected word text
    window.draw(selectedWordText);

    // Draw score
    window.draw(scoreText);

    window.display();
}

void GridGUI::handleMouseClick(const sf::Vector2i& mousePos) {
    int row = mousePos.y / 50;
    int col = mousePos.x / 50;

    // Assume word search logic to check if a valid word is selected
    std::vector<sf::Vector2i> wordCoords = grid.findWordCoordinates(row, col); // Example method

    if (!wordCoords.empty()) {
        highlightWord(wordCoords);
        selectedWordText.setString("Word Found: " + grid.getWordAtCoords(wordCoords)); // Assume getWordAtCoords method exists
    } else {
        selectedWordText.setString("Invalid Word");
    }
}

void GridGUI::handleMouseRelease(const sf::Vector2i& mousePos) {
    // Handle mouse release to finalize word selection
}

void GridGUI::highlightWord(const std::vector<sf::Vector2i>& wordCoords) {
    resetHighlightedCells();

    for (const auto& coord : wordCoords) {
        sf::RectangleShape highlightCell(sf::Vector2f(50, 50));
        highlightCell.setFillColor(sf::Color(255, 255, 0, 128)); // Yellow transparent highlight
        highlightCell.setPosition(coord.x * 50, coord.y * 50);
        highlightedCells.push_back(highlightCell);
    }
}

void GridGUI::resetHighlightedCells() {
    highlightedCells.clear();
}

void GridGUI::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                handleMouseClick(sf::Mouse::getPosition(window));
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                handleMouseRelease(sf::Mouse::getPosition(window));
            }
        }

        drawGrid();
    }
}
