#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include "Simulation.h"

int main() {
    Simulation simulation{50, 9};
    simulation.run();
    return 0;
}
