#include "ui.h"

unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT) {
    ui->width = WIDTH;
    ui->height = HEIGHT;
    ui->window = NULL;
    ui->renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("sdl could not initialize");
        return 1;
    } else {
        ui->window = SDL_CreateWindow(title, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
        if (!ui->window) {
            printf("Window creation failed: %s\n", SDL_GetError());
            return 2;
        }
        ui->renderer = SDL_CreateRenderer(ui->window, NULL);
        if (!ui->renderer) {
            printf("Renderer creation failed: %s\n", SDL_GetError());
            return 3;
        }
    }
    printf("Initialized %s\n", title);
    return 0;
}

void UI_DrawGrid(ui_t* ui) {}

void UI_Poll(ui_t* ui) {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&ui->events)) {
            if (ui->events.type == SDL_EVENT_QUIT) {
                quit = !quit;
            }
        }
        SDL_SetRenderDrawColor(ui->renderer, 0x28, 0x28, 0x28, 255); // RGBA: black
        SDL_RenderClear(ui->renderer);
        SDL_RenderPresent(ui->renderer);
    }
}

void UI_Destroy(ui_t* ui) {
    SDL_DestroyWindow(ui->window);
    SDL_Quit();
}
