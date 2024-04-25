#include "Simulation.h"
#include <raylib.h>
#include <iostream>

Simulation::Simulation(int cellSize, int numCells) : cellSize(cellSize), numCells(numCells),
                                                     grid(Grid(numCells, cellSize)) {
    InitWindow(cellSize * numCells, cellSize * numCells, "Game of life");
}

void Simulation::run() {
    SetTargetFPS(12);

    constexpr Color background = {39, 39, 39, 255};
    bool isRunning = false;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            isRunning = !isRunning;
        }
        update(isRunning);
        BeginDrawing();
        ClearBackground(background);
        grid.draw();
        EndDrawing();
    }
}

Simulation::~Simulation() {
    CloseWindow();
}

void Simulation::update(bool isRunning) {
    int x = GetMouseX() / cellSize;
    int y = GetMouseY() / cellSize;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        x = GetMouseX() / cellSize;
        y = GetMouseY() / cellSize;
        grid.setState(x, y, State::ALIVE);
    }
    std::vector<Cell> toBeUpdated;
    if (isRunning) {
        for (int i{}; i < numCells; ++i) {
            for (int j{}; j < numCells; ++j) {
                int sum = grid.countNeighbor(i, j);
                if (grid.getState(i, j) == State::ALIVE) {
                    if (sum < 2 || sum > 3) {
                        toBeUpdated.push_back({.x = i, .y = j, .state = State::DEAD});
                        //tmpGrid.setState(i, j, State::DEAD);
                    } else {
                        toBeUpdated.push_back({.x = i, .y = j, .state = State::ALIVE});
                        //tmpGrid.setState(i, j, State::ALIVE);
                    }
                } else {
                    if (sum == 3) {
                        toBeUpdated.push_back({.x = i, .y = j, .state = State::ALIVE});
                        //tmpGrid.setState(i, j, State::ALIVE);
                    }
                }
            }
        }
        for (Cell &cel: toBeUpdated) {
            grid.setState(cel.x, cel.y, cel.state);
        }
        toBeUpdated.clear();

    }


}
