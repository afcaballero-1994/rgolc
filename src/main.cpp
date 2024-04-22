#include <iostream>
#include <raylib.h>
#include "Grid.h"

using u8 = u_int8_t;
using u16 = u_int16_t;

int main() {
    constexpr u8 cellSize = 20;
    constexpr u8 numCells = 45;
    Grid grid {numCells, cellSize};
    constexpr int width = cellSize * numCells;
    constexpr int height = width;
    constexpr int lineThickness = 2;
    constexpr Color background = {39, 39, 39, 255};
    constexpr Color cellsColor = {255, 133, 141, 255};
    constexpr Color cellSelected = {166, 217, 247, 255};
    constexpr Color cellHovered = {147, 104, 183, 255};
    bool mouseClick = false;
    InitWindow(width, height, "Game of life");


    u8 x = 0;
    u8 y = 0;
    while(!WindowShouldClose()){
        x = GetMouseX() / cellSize;
        y = GetMouseY() / cellSize;
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            x = GetMouseX() / cellSize;
            y = GetMouseY() / cellSize;
            grid.setState(x, y);
        }

        BeginDrawing();
        ClearBackground(background);
        for(u8 i{}; i < numCells; i++){
            for(u8 j{}; j < numCells; j++){
                if(grid.getState(i, j)){
                    DrawRectangle(i * cellSize, j * cellSize, cellSize -2, cellSize - 2, cellSelected);
                } else if(i == x && j == y){
                    DrawRectangle(i * cellSize, j * cellSize, cellSize -2, cellSize - 2, cellHovered);
                } else{
                    DrawRectangle(i * cellSize, j * cellSize, cellSize -2, cellSize - 2, cellsColor);
                }
            }
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
