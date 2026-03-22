#include "cells.h"

void CELLS_Initialize(cell_grid_t* cell_grid, unsigned int width, unsigned int height) {
    cell_grid->width = width;
    cell_grid->height = height;
    cell_grid->cells = malloc(sizeof(cell_t) * width * height);
    for (int i = 0; i < width * height; i++) {
        cell_grid->cells[i].state = dead;
    }
}

void CELLS_Initialize_random(cell_grid_t* cell_grid, unsigned int width, unsigned int height) {
    cell_grid->width = width;
    cell_grid->height = height;
    cell_grid->cells = malloc(sizeof(cell_t) * width * height);
    srand(time(NULL));
    for (int i = 0; i < width * height; i++) {
        cell_grid->cells[i].state = rand() % 2 == 0 ? dead : alive;
    }
}

void CELLS_Print(cell_grid_t* cell_grid) {
    for (unsigned int i = 0; i < cell_grid->height; i++) {
        for (unsigned int j = 0; j < cell_grid->width; j++) {
            unsigned int index = (i * cell_grid->height) + j;
            printf("%d ", cell_grid->cells[index].state == dead ? 0 : 1);
        }
        printf("\n");
    }
}

unsigned int CELLS_GetNeighborsNumber(cell_grid_t* cell_grid, unsigned int x, unsigned int y) {
    unsigned int n = 0;

    for (int i = x - 1; i < x + 2; i++) {
        for (int j = y - 1; j < y + 2; j++) {
            if (i > 0 && j > 0 && i < cell_grid->width && j < cell_grid->height) {
                //printf("%d %d\n", i, j);
                if(cell_grid->cells[CELLS_GetIndex(cell_grid, i, j)].state == alive) {
                    n++;
                }
            }
        }
    }

    if (cell_grid->cells[CELLS_GetIndex(cell_grid, x, y)].state == alive) {
        n--;
    }


    return n;
}

cell_state_t CELLS_ApplyRule(cell_t* cell, unsigned int neighbors_number) {
    cell_state_t new_state = dead;
    if (cell->state == alive) {
        if (neighbors_number == 2 || neighbors_number == 3) {
            new_state = alive;
        }
    }

    if (cell->state == dead) {
        if (neighbors_number == 3) {
            new_state = alive;
        }
    }
    return new_state;
}

void CELLS_Update(cell_grid_t* cell_grid) {
    cell_grid_t new_cell_grid;
    CELLS_Initialize(&new_cell_grid, cell_grid->width, cell_grid->height);
    for (unsigned int i = 0; i < cell_grid->width; i++) {
        for (unsigned int j = 0; j < cell_grid->height; j++) {
            unsigned int n = CELLS_GetNeighborsNumber(cell_grid, i, j);
            unsigned int index = CELLS_GetIndex(cell_grid, i, j);
            cell_t* cell = &cell_grid->cells[index];
            new_cell_grid.cells[index].state = CELLS_ApplyRule(cell, n);
        }
    }
    cell_t* temp;
    temp = new_cell_grid.cells;
    new_cell_grid.cells = cell_grid->cells;
    cell_grid->cells = temp;
    CELLS_Destroy(&new_cell_grid);
}

unsigned int CELLS_GetIndex(cell_grid_t* cell_grid, unsigned int x, unsigned int y) {
    return (y * cell_grid->width) + x;
}

void CELLS_Destroy(cell_grid_t* cell_grid) {
    free(cell_grid->cells);
}
