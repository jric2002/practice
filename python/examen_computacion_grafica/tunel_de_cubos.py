import pygame
from pygame.locals import *
import random
from OpenGL.GL import *
from OpenGL.GLU import *
def cubo():   #Dibuja el cubo
  vertices = (
    (-1,  1, -1),
    ( 1,  1, -1),
    ( 1,  1,  1),
    (-1,  1,  1),
    (-1, -1, -1),
    ( 1, -1, -1),
    ( 1, -1,  1),
    (-1, -1,  1),
  )
  aristas = (
    (0, 1),
    (0, 3),
    (0, 4),
    (2, 1),
    (2, 3),
    (2, 6),
    (5, 1),
    (5, 4),
    (5, 6),
    (7, 3),
    (7, 4),
    (7, 6),
  )
  glBegin(GL_LINES)
  for arista in aristas:
    for vertice in arista:
      glVertex3fv(vertices[vertice])
  glEnd()
#ventana opengl
pygame.init()
screen_width = 900
screen_height = 600
pygame.display.set_mode((screen_width, screen_height), DOUBLEBUF | OPENGL)
pygame.display.set_caption("Tunel De Cubos")
gluPerspective(10, (screen_width / screen_height), 0.1, 80.0)  # Ajustar plano de recorte
glTranslatef(0.0, 0.0, -50)  # Alejar la vista
num_cubos = 50
cubos = []
for i in range(num_cubos):
  x = random.uniform(-1, 1)
  y = random.uniform(-1, 1)
  z = random.uniform(-1, 1)
  vel_x = random.uniform(-0.1, 0.1)
  vel_y = random.uniform(-0.1, 0.1)
  vel_z = 0.3
  rotation = random.uniform(0, 360)
  cubos.append([x, y, z, vel_x, vel_y, vel_z, rotation])
cube_scale = 0.2
clock = pygame.time.Clock()
game_over = False
while not game_over:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      game_over = True
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
  for cube in cubos:
    x, y, z, vel_x, vel_y, vel_z, rotation = cube
    x += vel_x
    y += vel_y
    z += vel_z
    if abs(x) > (screen_width - 10) or abs(y) > (screen_height - 10) or abs(z) > 40:  # Verificar límites de pantalla
      cubos.remove(cube)
    else:
      cube[0] = x
      cube[1] = y
      cube[2] = z
      cube[6] += 1-5
      glPushMatrix()
      glTranslatef(x, y, z)
      glRotatef(rotation, 1, 1, 1)
      glScalef(cube_scale, cube_scale, cube_scale)
      cubo()
      glPopMatrix()
  pygame.display.flip()
  clock.tick(10)
pygame.quit()