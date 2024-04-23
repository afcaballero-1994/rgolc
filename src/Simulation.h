#pragma once

#include "Grid.h"

class Simulation {
public:
    Simulation(int cellSize, int numCells);

    void run();

    ~Simulation();

    void update(bool isRunning);

private:
    int cellSize;
    int numCells;
    Grid grid;
};