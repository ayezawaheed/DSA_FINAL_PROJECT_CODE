#ifndef GRIDGUI_H
#define GRIDGUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Grid.h" // Include your existing Grid class

class GridGUI{
public:
    GridGUI(int rows, int cols, const std::vector<std::string>& dictionary);
    void run();
private:
    int rows, cols;
    std::vector<std::string> dictionary;
    Grid grid;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text selectedWordText;
    sf::Text scoreText;
    sf::RectangleShape gridCell;
    std::vector<sf::RectangleShape> highlightedCells;

    void drawGrid();
    void handleMouseClick(const sf::Vector2i& mousePos);
    void handleMouseRelease(const sf::Vector2i& mousePos);
    void highlightWord(const std::vector<sf::Vector2i>& wordCoords);
    void resetHighlightedCells();
};

#endif // GRIDGUI_H
