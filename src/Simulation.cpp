#include "Simulation.h"
#include <raylib.h>

Simulation::Simulation(int cellSize, int numCells): cellSize(cellSize), numCells(numCells), grid(Grid(numCells, cellSize)){
    InitWindow(cellSize * numCells, cellSize * numCells, "Game of life");
}

void Simulation::run() {

    constexpr Color background = {39, 39, 39, 255};

    while(!WindowShouldClose()){
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
    //Grid tmpGrid = grid;
    int x = GetMouseX() / cellSize;
    int y = GetMouseY() / cellSize;
    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        x = GetMouseX() / cellSize;
        y = GetMouseY() / cellSize;
        grid.setState(x, y, State::ALIVE);
    }

    if(IsKeyPressed(KEY_SPACE)){
        for(int i {}; i < numCells; ++i){
            for(int j{}; j < numCells; ++j){
                int sum = grid.countNeighbor(i, j);
                if(grid.getState(i,j) == State::ALIVE && sum >= 4){
                    grid.setState(i, j, State::DEAD);
                }
                else if(grid.getState(i,j) == State::DEAD && sum == 3){
                    grid.setState(i,j, State::ALIVE);
                } else if(grid.getState(i,j) == State::ALIVE && sum < 2){
                    grid.setState(i, j, State::DEAD);
                }
            }
        }
    }

}
