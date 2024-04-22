#pragma once
#include <vector>
#include <raylib.h>

enum class State{
    ALIVE,
    DEAD,
    HOVERED
};

struct Cell{
    State state;
    void draw(int x, int y, int lineThickness, int cellSize, Color color);
};

class Grid{
public:
    explicit Grid(int numCells, int cellSize);
    Grid(Grid& c);
    [[nodiscard]] State getState(int i, int j) const;
    [[nodiscard]] int countNeighbor(int i, int j) const;
    void setState(int i, int j, State state);
    void draw();
private:
    int numcellsPerRow;
    int cellSize;
    std::vector<Cell> grid;
};