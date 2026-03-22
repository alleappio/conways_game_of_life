#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    unsigned int horizontal_number;
    unsigned int vertical_number;
    unsigned int horizontal_step;
    unsigned int vertical_step;
} grid_t;

typedef struct {
    unsigned int width;
    unsigned int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event events;
} ui_t;



void init_grid(ui_t* ui, grid_t* grid, unsigned int vertical_number, unsigned int horizontal_number);

unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT);
void UI_DrawGrid(ui_t* ui, grid_t* grid);
void UI_Loop(ui_t* ui, grid_t* grid);
void UI_Destroy(ui_t* ui);

#endif // UI_H
