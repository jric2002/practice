import pygame
import random
import math
# Dimensiones de la pantalla
ancho = 800
alto = 600
# Colores
white = (255, 255, 255)
# Clase para representar una pelotita
class Pelotita:
  def __init__(self, x, y, sx, sy, radio, color):
    self.x = x
    self.y = y
    self.sx = sx
    self.sy = sy
    self.radio = radio
    self.dx = random.choice([-1, 1])  # Dirección de movimiento en el eje x
    self.dy = random.choice([-1, 1])  # Dirección de movimiento en el eje y
    self.color = color
  def actualizar(self):
    self.x += (self.dx * self.sx)
    self.y += (self.dy * self.sy)
    # Revisar colisiones con los bordes de la pantalla
    if self.x - self.radio <= 0 or self.x + self.radio >= ancho:
        self.dx *= -1
    if self.y - self.radio <= 0 or self.y + self.radio >= alto:
        self.dy *= -1
  def draw(self, pantalla):
    pygame.draw.circle(pantalla, self.color, (self.x, self.y), self.radio)
# Función para subdividir una pelotita
def subdividir_pelotita(pelotita):
  if pelotita.radio > 2:
    new_radio = pelotita.radio / 2
    pelotita1 = Pelotita(pelotita.x - new_radio, pelotita.y - new_radio, pelotita.sx, pelotita.sy, new_radio, pelotita.color)
    pelotita2 = Pelotita(pelotita.x, pelotita.y, pelotita.sx, pelotita.sy, new_radio, pelotita.color)
    pelotita3 = Pelotita(pelotita.x + new_radio, pelotita.y + new_radio, pelotita.sx, pelotita.sy, new_radio, pelotita.color)
    return [pelotita1, pelotita2, pelotita3]
  else:
    return []
# Inicializar Pygame
pygame.init()
# Crear la pantalla
pantalla = pygame.display.set_mode((ancho, alto))
pygame.display.set_caption("Pelotas en colisión")
reloj = pygame.time.Clock()
pelotitas = []
# Crear pelotitas iniciales
r = 30
coeficiente = 4
speed_x = speed_y = 3
for _ in range(4):
  radio = coeficiente * r
  s = True
  while s:
    x = random.randint(radio, ancho - radio)
    y = random.randint(radio, alto - radio)
    s = False
    for i in range(0, len(pelotitas)):
      distancia = ((pelotitas[i].x - x) ** 2 + (pelotitas[i].y - y) ** 2) ** 0.5
      if distancia < pelotitas[i].radio + radio:
        s = True
        break
  color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
  pelotitas.append(Pelotita(x, y, speed_x, speed_y, radio, color))
  coeficiente /= 2
# Bucle principal del juego
cerrar = True
while cerrar:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      cerrar = False
  # Actualizar las pelotitas
  for pelotita in pelotitas:
    pelotita.actualizar()
  # Revisar colisiones entre las pelotitas
  for i in range(len(pelotitas)):
    for j in range(i + 1, len(pelotitas)):
      pelotita1 = pelotitas[i]
      pelotita2 = pelotitas[j]
      distancia = math.sqrt(math.pow(pelotita1.x - pelotita2.x, 2) + math.pow(pelotita1.y - pelotita2.y, 2))
      if distancia <= pelotita1.radio + pelotita2.radio:
        # Colisión detectada, subdividir las pelotitas
        new_pelotitas = subdividir_pelotita(pelotita1) + subdividir_pelotita(pelotita2)
        pelotitas.extend(new_pelotitas)
        pelotitas.remove(pelotita1)
        pelotitas.remove(pelotita2)
        break
    # Eliminar pelotitas con radio r/2
    pelotitas = [pelotita for pelotita in pelotitas if pelotita.radio > radio / 2]
    # Limpiar la pantalla
    pantalla.fill(white)
    # Dibujar las pelotitas
    for pelotita in pelotitas:
        pelotita.draw(pantalla)
    # Actualizar la pantalla
    pygame.display.flip()
    # Controlar la velocidad de actualización
    reloj.tick(60)
# Salir del programa
pygame.quit()
