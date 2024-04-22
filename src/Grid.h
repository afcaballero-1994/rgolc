#pragma once
#include <vector>

struct Cell{
    bool isAlive;
};

class Grid{
public:
    explicit Grid(int numCells, int cellSize);
    [[nodiscard]] bool getState(int i, int j) const;
    [[nodiscard]] int countNeighbor(int i, int j) const;
    void setState(int i, int j);
    int getCellSize() const;
private:
    int numcellsPerRow;
    int cellSize;
    std::vector<Cell> grid;
};