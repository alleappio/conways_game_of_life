import pygame
import numpy
from Cells import *
from constants import *

def draw_grid(screen):
    hLinesNumber = GRID["WIDTH"]
    vLinesNumber = GRID["HEIGHT"]
    for i in range(0,int(hLinesNumber)):
        x = i*SCREEN["WIDTH"]/hLinesNumber
        pygame.draw.line(screen, COLORS["LINE_COLOR"],  (x, 0), (x, SCREEN["HEIGHT"]))
    for i in range(0,int(vLinesNumber)):
        y = i*SCREEN["HEIGHT"]/vLinesNumber
        pygame.draw.line(screen, COLORS["LINE_COLOR"],  (0, y), (SCREEN["WIDTH"], y))
 
def draw_cells(screen, cells):
    cellMatrix = cells.getCellMatrix()
    offset = 4
    print(cellMatrix)
    w = SCREEN["WIDTH"]/GRID["WIDTH"]-offset
    h = SCREEN["HEIGHT"]/GRID["HEIGHT"]-offset
    for i in range(GRID["WIDTH"]):
        for j in range(GRID["HEIGHT"]):
            if cellMatrix[i,j] == 1:
                y1 = i*(SCREEN["WIDTH"]/GRID["WIDTH"])+(offset/2)
                x1 = j*(SCREEN["HEIGHT"]/GRID["HEIGHT"])+(offset/2)
                pygame.draw.rect(screen, COLORS["LINE_COLOR"], pygame.Rect(x1,y1,w,h))

def loop(screen, cells):
    background = (50,50,50)
    running = True
    while running:
        screen.fill(background)
        draw_grid(screen)
        draw_cells(screen, cells)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        pygame.display.update()


def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN["WIDTH"],SCREEN["HEIGHT"]))
    pygame.display.set_caption("Conway's game of life")
    cells = Cells(GRID["WIDTH"], GRID["HEIGHT"])
    cells.randomFill()
    loop(screen, cells)
    pygame.quit()


if __name__ == '__main__':
    main()
