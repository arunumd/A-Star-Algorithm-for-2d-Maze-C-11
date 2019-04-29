#include <iostream>
#include "../include/A-Star.h"

int main() {
    Maze game;
    game.Scan();
    game.Action();
    game.PlotTrajectory();

    return 0;
}