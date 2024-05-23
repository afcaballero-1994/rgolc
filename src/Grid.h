#pragma once
#include <vector>
#include <raylib.h>


struct Cell{
    int x;
    int y;
    int cellSize;
    bool currentState;
    bool nextState;
    void draw(int lineThickness, Color color) const;
};

class Grid{
public:
    explicit Grid(int numCells, int cellSize);
    Grid(int *home);
    [[nodiscard]] bool getState(int i, int j) const;
    [[nodiscard]] int countNeighbor(int i, int j) const;
    void setState(int i, int j, bool state);
    void updateState();
    void draw();

private:
    int numCells;
    std::vector<Cell> grid;
};