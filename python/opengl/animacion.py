import pygame
from pygame.locals import *
pygame.init()
white = (255,255,255)
bg = (0,0,0)
screen_size = (800,600)
c_x, c_y = screen_size[0]/2, screen_size[1]/2
pantalla = pygame.display.set_mode(screen_size)
reloj = pygame.time.Clock()
# Datos de la Animacion (Pelota)
pelota_x, pelota_y, radio = c_x, c_y, 15
pelota_vel_x, pelota_vel_y = 3, 3
Cerrar = False
while not Cerrar:
  for event in pygame.event.get():
    if event.type == QUIT:
      Cerrar = True
    if event.type == KEYDOWN:
      if event.key == K_ESCAPE:
        Cerrar = True
  # establecer el movimineto
  pelota_x += pelota_vel_x
  pelota_y += pelota_vel_y
  # Restricciones para el circulo
  # En el Eje Y
  if pelota_y > (screen_size[1] - radio) or pelota_y < radio:
    pelota_vel_y *= -1
  # En el Eje X
  if pelota_x > (screen_size[0] - radio) or pelota_x < radio:
    pelota_vel_x *= -1
  pantalla.fill(bg)
  pygame.draw.circle(pantalla, white, (pelota_x, pelota_y), radio)
  pygame.display.flip()
  reloj.tick(60)
pygame.quit()