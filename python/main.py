import pygame
from constants import *

def loop(screen):
    background = (50,50,50)
    running = True
    while running:
        screen.fill(background)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        pygame.display.update()


def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN["WIDTH"],SCREEN["HEIGHT"]))
    pygame.display.set_caption("Conway's game of life")

    loop(screen)
    pygame.quit()


if __name__ == '__main__':
    main()
