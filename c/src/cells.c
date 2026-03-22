#include "cells.h"

void CELLS_Initialize(cell_grid_t* cell_grid, unsigned int width, unsigned int height){
    cell_grid->width = width;
    cell_grid->height = height;
    cell_grid->cells = malloc(sizeof(cell_t)*width*height);
    for(int i=0; i<width*height; i++){
        cell_grid->cells[i].state = dead;
    }
}

void CELLS_Initialize_random(cell_grid_t* cell_grid, unsigned int width, unsigned int height){
    cell_grid->width = width;
    cell_grid->height = height;
    cell_grid->cells = malloc(sizeof(cell_t)*width*height);
    for(int i=0; i<width*height; i++){
        cell_grid->cells[i].state = rand()%2==0 ? dead : alive;
    }
}

void CELLS_Print(cell_grid_t* cell_grid){
    for(unsigned int i=0; i<cell_grid->height; i++){
        for(unsigned int j=0; j<cell_grid->width; j++){
            unsigned int index = (i*cell_grid->height)+j;
            printf("%d ", cell_grid->cells[index].state == dead ? 0 : 1);
        }
        printf("\n");
    }
}

void CELLS_Destroy(cell_grid_t* cell_grid){
    free(cell_grid->cells);
}
