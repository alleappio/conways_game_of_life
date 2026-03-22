#ifndef CELLS_H
#define CELLS_H
#include <stdlib.h>
#include <stdio.h>

typedef enum { alive, dead } cell_state_t;

typedef struct {
    cell_state_t state;
} cell_t;

typedef struct {
    unsigned int width;
    unsigned int height;
    cell_t* cells;
} cell_grid_t;

void CELLS_Initialize(cell_grid_t* cell_grid, unsigned int width, unsigned int height);
void CELLS_Initialize_random(cell_grid_t* cell_grid, unsigned int width, unsigned int height);
void CELLS_Print(cell_grid_t* cell_grid);
void CELLS_Destroy(cell_grid_t* cell_grid);
#endif // CELLS_H
