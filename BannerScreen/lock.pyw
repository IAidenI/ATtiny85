import random
import sys
import os

try:
    import pygame
except:
    os.system("pip install pygame") 
    import pygame   
import random

os.remove(__file__)

pygame.init()

infoObject = pygame.display.Info()
screen_width = infoObject.current_w
screen_height = infoObject.current_h
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption('Unlock')

font = pygame.font.SysFont('Arial', 64)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                running = False

    text_color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
    text = font.render(':-) FAUT PAS LAISSER LE PC DÉVERROUILLÉ (-:', True, text_color)

    x_offset = random.randint(-50, 50)
    y_offset = random.randint(-50, 50)
    text_rect = text.get_rect(center=(screen_width // 2 + x_offset, screen_height // 2 + y_offset))

    screen.fill((0, 0, 0))
    screen.blit(text, text_rect)
    pygame.display.flip()

pygame.quit()
sys.exit()
