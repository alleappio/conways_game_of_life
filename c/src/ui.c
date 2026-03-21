#include "ui.h"

unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT) {
    ui->width = WIDTH;
    ui->height = HEIGHT;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("sdl could not initialize");
        return 1;
    } else {
        ui->window = SDL_CreateWindow(
          title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        printf("Initialized window %s\n", title);
        if (ui->window == NULL) {
            printf("could not create window: %s", SDL_GetError());
            return 2;
        } else {
            ui->surface = SDL_GetWindowSurface(ui->window);

            SDL_FillRect(ui->surface, NULL, SDL_MapRGB(ui->surface->format, 0x0f, 0x0f, 0x0f));
            SDL_UpdateWindowSurface(ui->window);

            SDL_Event e;
        }
    }
    printf("Initialized %s\n", title);
    return 0;
}

void UI_DrawGrid(ui_t* ui) {

}

void UI_Poll(ui_t* ui) {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&ui->events)) {
            if (ui->events.type == SDL_QUIT) {
                quit = !quit;
            }
        }
    }
}

void UI_Destroy(ui_t* ui) {
    SDL_DestroyWindow(ui->window);
    SDL_Quit();
}
