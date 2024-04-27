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
            grid[i * numCells + j].state = State::DEAD;
            grid[i * numCells + j].x = i * cellSize;
            grid[i * numCells + j].y = j * cellSize;
            grid[i * numCells + j].cellSize = cellSize;
        }
    }
}

State Grid::getState(const int i, const int j) const {
    return grid[i * numCells + j].state;
}

int Grid::countNeighbor(const int i, const int j) const {
    int sum = 0;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if (grid[acpMod((i + x), numCells) * numCells + acpMod((j + y), numCells)].state ==
                State::ALIVE && x != 0 && y != 0) {
                sum += 1;
            }
        }
    }
    return sum;
}

void Grid::setState(const int i, const int j, State state) {
    grid[i * numCells + j].state = state;
}

void Grid::draw() {
    constexpr Color cellDeadColor = {255, 133, 141, 255};
    constexpr Color cellAliveColor = {166, 217, 247, 255};
    constexpr Color cellHoveredColor = {147, 104, 183, 255};
    constexpr int lineThickness = 2;
    for (int i{}; i < numCells; i++) {
        for (int j{}; j < numCells; j++) {
            switch (grid[i * numCells + j].state) {
                case State::ALIVE:
                    grid[i * numCells + j].draw(
                            lineThickness,
                            cellAliveColor
                    );
                    break;
                case State::DEAD:
                    grid[i * numCells + j].draw(
                            lineThickness,
                            cellDeadColor
                    );
                    break;
                case State::HOVERED:
                    grid[i * numCells + j].draw(
                            lineThickness,
                            cellHoveredColor
                    );
                    break;
            }
        }

    }
}

void Cell::draw(int lineThickness, Color color) const{
    DrawRectangle(x, y, cellSize - lineThickness, cellSize - lineThickness, color);
}
