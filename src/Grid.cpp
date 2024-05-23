#include <iostream>
#include "Grid.h"

inline int acpMod(int a, int b) {
    int result = a % b;
    if (result < 0) {
        return result + b;
    } else {
        return result;
    }
}

Grid::Grid(const int numCells, const int cellSize) {
    this->numCells = numCells;
    grid.reserve(numCells * numCells);

    for (size_t i{}; i < numCells; ++i) {
        for (size_t j{}; j < numCells; ++j) {
            grid[i * numCells + j].currentState = false;
            grid[i * numCells + j].nextState = false;
            grid[i * numCells + j].x = i * cellSize;
            grid[i * numCells + j].y = j * cellSize;
            grid[i * numCells + j].cellSize = cellSize;
        }
    }

}

bool Grid::getState(const int i, const int j) const {
    return grid[i * numCells + j].currentState;
}

int Grid::countNeighbor(const int i, const int j) const {
    int sum = 0;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if(!(x == 0 && y == 0)){
                if (grid[acpMod((i + x), numCells) * numCells + acpMod((j + y), numCells)].currentState) {
                    sum += 1;
                }
            }
        }
    }
    return sum;
}

void Grid::setState(const int i, const int j, bool state) {
    grid[i * numCells + j].nextState = state;
}

void Grid::updateState() {
    for(int i{}; i < numCells * numCells; ++i){
        grid[i].currentState = grid[i].nextState;
    }
}

void Grid::draw() {
    constexpr Color cellDeadColor = {255, 133, 141, 255};
    constexpr Color cellAliveColor = {166, 217, 247, 255};
    //constexpr Color cellHoveredColor = {147, 104, 183, 255};
    constexpr int lineThickness = 2;
    for (int i{}; i < numCells; i++) {
        for (int j{}; j < numCells; j++) {
            if (grid[i * numCells + j].currentState) {
                grid[i * numCells + j].draw(
                        lineThickness,
                        cellAliveColor
                );
            } else {

                grid[i * numCells + j].draw(
                        lineThickness,
                        cellDeadColor
                );
            }
        }
    }

}

Grid::Grid(int *home) {

}


void Cell::draw(int lineThickness, Color color) const {
    DrawRectangle(x, y, cellSize - lineThickness, cellSize - lineThickness, color);
}

