#pragma once
#include "Grid.h"

class Simulation{
public:
    Simulation(int cellSize, int numCells);
    void run();
    ~Simulation();
    void update();
private:
    int cellSize;
    int numCells;
    Grid grid;
};