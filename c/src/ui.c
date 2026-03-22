#include "ui.h"

void init_grid(ui_t* ui, grid_t* grid, unsigned int vertical_number, unsigned int horizontal_number){
    grid->horizontal_number = horizontal_number;
    grid->vertical_number = vertical_number;
    grid->horizontal_step = ui->width/horizontal_number;
    grid->vertical_step = ui->height/vertical_number;
}
unsigned int UI_Initialize(ui_t* ui, char* title, int WIDTH, int HEIGHT) {
    ui->width = WIDTH;
    ui->height = HEIGHT;
    ui->window = NULL;
    ui->renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("sdl could not initialize");
        return 1;
    } else {
        ui->window = SDL_CreateWindow(title, WIDTH, HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP);
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


void UI_DrawGrid(ui_t* ui, grid_t* grid) {
    SDL_SetRenderDrawColor(ui->renderer, 0xeb, 0xdb, 0xb2, 0xff);

    for(int i=0; i<grid->horizontal_number; i++){
        int x = i*grid->horizontal_step;
        SDL_RenderLine(ui->renderer, x, 0, x, ui->height);
    }

    for(int j=0; j<grid->vertical_number; j++){
        int y = j*grid->vertical_step;
        SDL_RenderLine(ui->renderer, 0, y, ui->width, y);
    }
}

void UI_Loop(ui_t* ui, grid_t* grid) {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&ui->events)) {
            if (ui->events.type == SDL_EVENT_QUIT) {
                quit = !quit;
            }
        }
        SDL_SetRenderDrawColor(ui->renderer, 0x28, 0x28, 0x28, 255); // RGBA: black
        SDL_RenderClear(ui->renderer);
        UI_DrawGrid(ui, grid);
        SDL_RenderPresent(ui->renderer);
    }
}

void UI_Destroy(ui_t* ui) {
    SDL_DestroyWindow(ui->window);
    SDL_Quit();
}
