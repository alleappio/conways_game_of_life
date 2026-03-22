#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
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

    grid_t grid;
} ui_t;

unsigned int UI_Initialize(ui_t* ui,
                           char* title,
                           int width,
                           int height,
                           unsigned int horizontal_cells_number,
                           unsigned int vertical_cells_number);

void UI_DrawGrid(ui_t* ui);
void UI_Loop(ui_t* ui);
void UI_Destroy(ui_t* ui);

#endif // UI_H
