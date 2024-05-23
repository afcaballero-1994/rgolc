#include "Simulation.h"
#include <raylib.h>
#include <iostream>

Simulation::Simulation(int cellSize, int numCells) : cellSize(cellSize), numCells(numCells),
                                                     grid(Grid(numCells, cellSize)) {
    InitWindow(cellSize * numCells, cellSize * numCells, "Game of life");
}

Grid *hola = new Grid(nullptr);

void Simulation::run() {
    SetTargetFPS(5);

    constexpr Color background = {39, 39, 39, 255};
    while (!WindowShouldClose()) {
        inputHandling();
        update();
        BeginDrawing();
        ClearBackground(background);
        grid.draw();
        EndDrawing();
    }
}

Simulation::~Simulation() {
    CloseWindow();
}

void Simulation::update() {

    if(isRunning) {
        for (int i{}; i < numCells; ++i) {
            for (int j{}; j < numCells; ++j) {
                int sum = grid.countNeighbor(i, j);
                if (grid.getState(i, j) && sum < 2) {
                    grid.setState(i, j, false);
                } else if (grid.getState(i, j) && sum > 3) {
                    grid.setState(i, j, false);
                } else if (!grid.getState(i, j) && sum == 3) {
                    grid.setState(i, j, true);
                }
            }
        }
        grid.updateState();


    }

}

void Simulation::inputHandling() {
    if (IsKeyPressed(KEY_SPACE)) {
        isRunning = !isRunning;
    }
    int x = GetMouseX() / cellSize;
    int y = GetMouseY() / cellSize;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        x = GetMouseX() / cellSize;
        y = GetMouseY() / cellSize;
        grid.setState(x, y, true);
    }
}
