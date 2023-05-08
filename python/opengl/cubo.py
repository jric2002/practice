from OpenGL.GL import *
import pygame
from pygame.locals import *
from random import *
gluPerspective(45, pantalla[0]/pantalla[1], 0.1, 50)
glTranslatef(0.0, 0.0, -5)
glRotatef(0.0, 0.0, 0.0, 0.0)
vertices = (
  (-1,1,-1) #p0
  (1,1,-1) #p1
  (1,1,1) #p2
  (-1,1,1) #p3
  (-1,-1,-1) #p4
  (1,-1,-1) #p5
  (1,-1,1) #p6
  (-1,-1,1) #p7
)
aristas=(
  (0,1),
  (0,3),
  (0,4),
  (2,1),
  (2,3),
  (2,6),
  (5,1),
  (5,4),
  (5,6),
  (7,3),
  (7,4),
  (7,6),
)
def Cubo():
  glBegin(GL_LINES):
  glColor3fv((1,1,1))
  for arista in aristas:
    for vertice in arista:
      glVertex3fv(vertices[vertice])
  glEnd()