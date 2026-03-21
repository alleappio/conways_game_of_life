#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event events;
} ui_t;

unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT);
void UI_DrawGrid(ui_t* ui);
void UI_Poll(ui_t* ui);
void UI_Destroy(ui_t* ui);

#endif // UI_H
