# import libreria as lib
# from libreria import metodo1, metodo2, metodo3, ...
# import libreria
# from libreria.modulo1 import *
from OpenGL.GL import *
import pygame
from pygame.locals import *
from random import *
# def Nombre_Funcion(param_1, param_2, ..., listas, dict, obj, ...):
  # Aqui todo el codigo
def Punto():
  glBegin(GL_POINTS)
  # Todo el codigo necesario
  glColor3fv([1, 0, 0])
  glVertex2f(.5, .5)
  glColor3fv((0, 1, 0))
  glVertex2f(.52, .52)
  glColor3fv([1, 1, 0])
  glVertex2f(.54, .54)
  # Lluvia de puntos
  for _ in range(100):
    x = randrange(-600, 600)/600
    y = randrange(-600, 600)/600
    r, g, b = random(), random(), random()
    # r = random()
    # g = random()
    # b = random()
    glColor3fv([r, g, b])
    glVertex2f(-random(), -random())
    glVertex2f(x,y)
  glEnd()
def Linea():
  glBegin(GL_POINTS)
  x = -1
  for _ in range(600):
    y = x
    glColor3fv([random(), random(), 0])
    glVertex2f(x, y)
    glVertex2f(x+0.2, y)
    x += 1/300
  glEnd()
def Parabola():
  glBegin(GL_POINTS)
  x = -1
  for _ in range(600):
    y = x ** 2
    glColor3fv([random(), random(), 0])
    glVertex2f(x, y)
    x += 1/300
  glEnd()
def Principal():
  pantalla = [600, 600]
  Cerrar = False
  pygame.init()
  pygame.display.set_mode(pantalla, DOUBLEBUF | OPENGL)
  pygame.display.set_caption("Primitivas - Computación Gráfica")
  while not Cerrar:
    for event in pygame.event.get():
      if event.type == QUIT:
        Cerrar = True
      if event.type == KEYDOWN:
        if event.key == K_ESCAPE:
          Cerrar = True
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    Punto()
    Linea()
    Parabola()
    pygame.display.flip()
    pygame.time.wait(60)
  pygame.quit()
Principal()