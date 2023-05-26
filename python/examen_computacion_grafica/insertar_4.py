import pygame
pygame.init()
pantalla = pygame.display.set_mode((800, 600))
reloj = pygame.time.Clock()
class Pelota:
  def __init__(self, radio):
    self.radio = radio
    pelota_pos = pygame.Vector2(pantalla.get_width() / 2, pantalla.get_height() / 2)
    pygame.draw.circle(pantalla, "red", pelota_pos, radio)
radio = 1

cerrar = False
while not cerrar:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      cerrar = True
  pantalla.fill("yellow")
  pygame.display.flip()
  reloj.tick(60)
pygame.quit()