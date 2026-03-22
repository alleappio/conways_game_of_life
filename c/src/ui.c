#include "ui.h"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

unsigned int UI_Initialize(ui_t* ui,
                           char* title,
                           int width,
                           int height,
                           unsigned int horizontal_cells_number,
                           unsigned int vertical_cells_number) {

    ui->width = width;
    ui->height = height;
    ui->window = NULL;
    ui->renderer = NULL;

    ui->grid.horizontal_number = horizontal_cells_number;
    ui->grid.vertical_number = vertical_cells_number;
    ui->grid.horizontal_step = ui->width / horizontal_cells_number;
    ui->grid.vertical_step = ui->height / vertical_cells_number;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("sdl could not initialize");
        return 1;
    } else {
        ui->window = SDL_CreateWindow(title, width, height, SDL_WINDOW_ALWAYS_ON_TOP);
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

void UI_DrawCells(ui_t* ui, cell_grid_t* cell_grid) {
    for (int i = 0; i < cell_grid->width; i++) {
        for (int j = 0; j < cell_grid->height; j++) {
            if (cell_grid->cells[CELLS_GetIndex(cell_grid, i, j)].state == alive) {
                SDL_FRect rect;
                rect.x = i * ui->grid.horizontal_step;
                rect.y = j * ui->grid.vertical_step;
                rect.w = ui->grid.horizontal_step;
                rect.h = ui->grid.vertical_step;

                // SDL_SetRenderDrawColor(ui->renderer, 0xeb, 0xdb, 0xb2, 0xff);
                SDL_RenderFillRect(ui->renderer, &rect);
            }
        }
    }
}

void UI_DrawGrid(ui_t* ui) {
    SDL_SetRenderDrawColor(ui->renderer, 0xeb, 0xdb, 0xb2, 0xff);

    for (int i = 0; i < ui->grid.horizontal_number; i++) {
        int x = i * ui->grid.horizontal_step;
        SDL_RenderLine(ui->renderer, x, 0, x, ui->height);
    }

    for (int j = 0; j < ui->grid.vertical_number; j++) {
        int y = j * ui->grid.vertical_step;
        SDL_RenderLine(ui->renderer, 0, y, ui->width, y);
    }
}

void UI_Loop(ui_t* ui, cell_grid_t* cell_grid) {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&ui->events)) {
            if (ui->events.type == SDL_EVENT_QUIT) {
                quit = !quit;
            }
        }
        SDL_SetRenderDrawColor(ui->renderer, 0x28, 0x28, 0x28, 255); // RGBA: black
        SDL_RenderClear(ui->renderer);
        UI_DrawGrid(ui);
        UI_DrawCells(ui, cell_grid);
        SDL_RenderPresent(ui->renderer);
    }
}

void UI_Destroy(ui_t* ui) {
    SDL_DestroyWindow(ui->window);
    SDL_Quit();
}
