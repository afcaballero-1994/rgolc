#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include "Simulation.h"

int main() {
    Simulation simulation{20, 50};
    simulation.run();
    return 0;
}
