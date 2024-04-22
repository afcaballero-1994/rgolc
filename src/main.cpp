#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include "Simulation.h"

int main() {
    Simulation simulation{25, 40};
    simulation.run();
    return 0;
}
