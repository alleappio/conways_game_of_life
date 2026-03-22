#ifndef CELLS_H
#define CELLS_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
unsigned int CELLS_GetIndex(cell_grid_t* cell_grid, unsigned int x, unsigned int y);

unsigned int CELLS_GetNeighborsNumber(cell_grid_t* cell_grid, unsigned int x, unsigned int y);
cell_state_t CELLS_ApplyRule(cell_t* cell, unsigned int neighbors_number);
void CELLS_Update(cell_grid_t* cell_grid);

void CELLS_Destroy(cell_grid_t* cell_grid);
#endif // CELLS_H
