#include "Grid.h"


Grid::Grid(const int numCells, const int cellSize) {
    this->numcellsPerRow = numCells;
    this->cellSize = cellSize;
    grid.reserve(numCells * numCells);

    for(size_t i {}; i < numcellsPerRow; ++i){
        for(size_t j {}; j < numcellsPerRow; ++j){
            grid[i * numcellsPerRow + j].isAlive = false;
        }
    }
}

bool Grid::getState(const int i, const int j) const{
    return grid[i * numcellsPerRow + j].isAlive;
}

int Grid::countNeighbor(const int i, const int j) const{
    int sum = 0;
    for(int x = -1; x < 2; x += 2){
        for(int y = -1; y < 2; y += 2){
            if(grid[(i + x) * numcellsPerRow + (j + y)].isAlive){
                sum += 1;
            }
        }
    }
    return sum;
}

void Grid::setState(const int i, const int j)  {
    grid[i * numcellsPerRow + j].isAlive = !grid[i * numcellsPerRow + j].isAlive;
}

int Grid::getCellSize() const {
    return this->cellSize;
}
