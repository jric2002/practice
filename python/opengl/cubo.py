from OpenGL.GL import *
from OpenGL.GLU import *
import pygame
from pygame.locals import *
# Vertice, Arista, Cara
vertices = (
  # X,  Y,  Z
  (-1,  1, -1),   # P0
  ( 1,  1, -1),   # P1
  ( 1,  1,  1),   # P2
  (-1,  1,  1),   # P3
  (-1, -1, -1),   # P4
  ( 1, -1, -1),   # P5
  ( 1, -1,  1),   # P6
  (-1, -1,  1),   # P7
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
def Cubo():
  glBegin(GL_LINES)
  glColor3fv((1,1,1))
  for arista in aristas:
    for vertice in arista:
      glVertex3fv(vertices[vertice])
  glEnd()
def Principal():
  pantalla = [600, 600]
  Cerrar = False
  pygame.init()
  pygame.display.set_mode(pantalla, DOUBLEBUF | OPENGL)
  pygame.display.set_caption("Primitivas - Cubo")
  gluPerspective(45, pantalla[0]/pantalla[1], 0.1, 50)
  glTranslatef(0.0, 0.0, -5)
  glRotatef(0.0, 0.0, 0.0, 0.0)
  while not Cerrar:
    for event in pygame.event.get():
      if event.type == QUIT:
        Cerrar = True
      if event.type == KEYDOWN:
        if event.key == K_ESCAPE:
          Cerrar = True
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    # glTranslatef(0.1, 0.1, -0.3)
    glRotatef(3.0, 0.0, 0.5, 0.5)
    # LLamada al cubo
    Cubo()
    pygame.display.flip()
    pygame.time.wait(60)
  pygame.quit()
Principal()