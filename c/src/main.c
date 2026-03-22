#include <stdio.h>

#include "cells.h"
#include "ui.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int H_CELLS = 50;
const int V_CELLS = 50;

int main() {
    ui_t ui;
    cell_grid_t cell_grid;

    CELLS_Initialize_random(&cell_grid, H_CELLS, V_CELLS);

    UI_Initialize(&ui, "conways game of life", WIDTH, HEIGHT, H_CELLS, V_CELLS);

    UI_Loop(&ui, &cell_grid);

    printf("destroying everything\n");
    CELLS_Destroy(&cell_grid);
    UI_Destroy(&ui);
}
