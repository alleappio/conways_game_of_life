#include <stdio.h>

#include "ui.h"

const int WIDTH = 600;
const int HEIGHT = 600;
const int H_CELLS = 10;
const int V_CELLS = 10;

int main() {
    ui_t ui;
    grid_t grid;
    UI_Initialize(&ui, "conways game of life", WIDTH, HEIGHT);
    init_grid(&ui, &grid, V_CELLS, H_CELLS);
    UI_Loop(&ui, &grid);
    UI_Destroy(&ui);
}
