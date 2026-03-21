#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Event events;
} ui_t;

unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT);
void UI_DrawGrid(ui_t* ui);
void UI_Poll(ui_t* ui);
void UI_Destroy(ui_t* ui);

#endif // UI_H
