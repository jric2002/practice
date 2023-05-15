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
# Datos de los Jugadores
pad, w_pal, h_pal = 15, 10, 80
speed_p1, speed_p2 = 0, 0
y_p1 = y_p2 = c_y - h_pal/2
Cerrar = False
while not Cerrar:
  for event in pygame.event.get():
    if event.type == QUIT:
      Cerrar = True
    # if event.type == KEYDOWN:
    #     if event.key == K_ESCAPE:
    #         Cerrar = True
    # Eventos para las paletas
    if event.type == pygame.KEYDOWN:    # Cuando presionamos una tecla
      if event.key == K_w:
        speed_p1 = -3
      if event.key == K_s:
        speed_p1 = 3
      if event.key == K_o:
        speed_p2 = -3
      if event.key == K_l:
        speed_p2 = 3
    if event.type == pygame.KEYUP:      # Cuando soltamos una tecla
      if event.key == K_w:
        speed_p1 = 0
      if event.key == K_s:
        speed_p1 = 0
      if event.key == K_o:
        speed_p2 = 0
      if event.key == K_l:
        speed_p2 = 0
  # establecer el movimineto
  pelota_x += pelota_vel_x
  pelota_y += pelota_vel_y
  # Control de las paletas ARRIBA/ABAJO
  y_p1 += speed_p1
  y_p2 += speed_p2
  # Restricciones para el circulo
  # En el Eje Y
  if pelota_y > (screen_size[1] - radio) or pelota_y < radio:
    pelota_vel_y *= -1
  # En el Eje X
  if pelota_x > (screen_size[0] - radio) or pelota_x < radio:
    pelota_x, pelota_y = c_x, c_y
    pelota_vel_x *= -1
    pelota_vel_y *= -1
  pantalla.fill(bg)
  pel = pygame.draw.circle(pantalla, white, (pelota_x, pelota_y), radio)
  p1 = pygame.draw.rect(pantalla, white, (pad, y_p1, w_pal, h_pal))
  p2 = pygame.draw.rect(pantalla, white, (screen_size[0] - (pad + w_pal), y_p2, w_pal, h_pal))
  # Detectar las colisiones de la pelota con las paletas
  if pel.colliderect(p1) or pel.colliderect(p2):
    pelota_vel_x *= -1
  pygame.display.flip()
  reloj.tick(60)
pygame.quit()