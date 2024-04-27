#pragma once

#include "Grid.h"

class Simulation {
public:
    Simulation(int cellSize, int numCells);

    void run();

    ~Simulation();

    void inputHandling();

    void update();

private:
    bool isRunning = false;
    int cellSize;
    int numCells;
    Grid grid;
};