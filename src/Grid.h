#pragma once
#include <vector>
#include <raylib.h>

enum class State{
    ALIVE,
    DEAD,
    HOVERED
};

struct Cell{
    int x;
    int y;
    int cellSize;
    State state;
    void draw(int lineThickness, Color color) const;
};

class Grid{
public:
    explicit Grid(int numCells, int cellSize);
    [[nodiscard]] State getState(int i, int j) const;
    [[nodiscard]] int countNeighbor(int i, int j) const;
    void setState(int i, int j, State state);
    void draw();

private:
    int numCells;
    std::vector<Cell> grid;
};