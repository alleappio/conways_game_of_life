#include <stdio.h>

#include "ui.h"

const int WIDTH = 640;
const int HEIGHT = 480;

int main() {
    ui_t ui;
    UI_Initialize(&ui, "conways game of life", WIDTH, HEIGHT);
    UI_Poll(&ui);
    UI_Destroy(&ui);
}
