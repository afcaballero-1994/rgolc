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
    this->numcellsPerRow = numCells;
    this->cellSize = cellSize;
    grid.reserve(numCells * numCells);

    for (size_t i{}; i < numcellsPerRow; ++i) {
        for (size_t j{}; j < numcellsPerRow; ++j) {
            grid[i * numcellsPerRow + j].state = State::DEAD;
        }
    }
}

State Grid::getState(const int i, const int j) const {
    return grid[i * numcellsPerRow + j].state;
}

int Grid::countNeighbor(const int i, const int j) const {
    int sum = -1;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if (grid[acpMod((i + x), numcellsPerRow) * numcellsPerRow + acpMod((j + y), numcellsPerRow)].state ==
                State::ALIVE) {
                sum += 1;
            }
        }
    }
    return sum;
}

void Grid::setState(const int i, const int j, State state) {
    grid[i * numcellsPerRow + j].state = state;
}

void Grid::draw() {
    constexpr Color cellDeadColor = {255, 133, 141, 255};
    constexpr Color cellAliveColor = {166, 217, 247, 255};
    constexpr Color cellHoveredColor = {147, 104, 183, 255};
    constexpr int lineThickness = 2;
    for (int i{}; i < numcellsPerRow; i++) {
        for (int j{}; j < numcellsPerRow; j++) {
            switch (grid[i * numcellsPerRow + j].state) {
                case State::ALIVE:
                    grid[i * numcellsPerRow + j].draw(
                            i * cellSize,
                            j * cellSize,
                            lineThickness,
                            cellSize,
                            cellAliveColor
                    );
                    break;
                case State::DEAD:
                    grid[i * numcellsPerRow + j].draw(
                            i * cellSize,
                            j * cellSize,
                            lineThickness,
                            cellSize,
                            cellDeadColor
                    );
                    break;
                case State::HOVERED:
                    grid[i * numcellsPerRow + j].draw(
                            i * cellSize,
                            j * cellSize,
                            lineThickness,
                            cellSize,
                            cellHoveredColor
                    );
                    break;
            }
        }

    }
}

Grid::Grid(Grid &c) {
    numcellsPerRow = c.numcellsPerRow;
    cellSize = c.cellSize;
    grid = c.grid;
}


void Cell::draw(int x, int y, int lineThickness, int cellSize, Color color) {
    DrawRectangle(x, y, cellSize - lineThickness, cellSize - lineThickness, color);
}
