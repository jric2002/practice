from OpenGL.GL import *
# GL    -> Trabaja o importa todos los comandos básicos
# GLU   -> (U - Utilities) Cilindro, Tetraedro, Icosaedro
# GLUT  -> (T - Toolkit) Comandos mas sofisticados
# GLX   -> Para dibujar formas en windows
import pygame
from pygame.locals import *
from random import randrange, random
def Funcion():
  glBegin(GL_POINTS)
  glEnd()
def Principal():
  # Aqui va todo el codigo necesario
  pantalla = [600, 600]
  cerrar = False
  pygame.init()
  pygame.display.set_mode(pantalla, DOUBLEBUF | OPENGL)
  pygame.display.set_caption("Primitivas - Computación Gráfica")
  while not cerrar:
    #esta capturando todos los eventos(cmara, mouse...)
    for event in pygame.event.get():
      if event.type == pygame.QUIT:
        cerrar = True
    # Limpiar la pantalla antes de renderizar los gráficos
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    # Seccion Dibujar las primitivas
    Punto()
    Parabola()
    Linea()
    #mostrar los eventos
    pygame.display.flip()
    #tiempo
    pygame.time.wait(100)
  pygame.quit()
def Punto():
  glBegin(GL_POINTS)
  # Color para el punto
  #  R  G  B
  glColor3fv([1, 0, 0])
  #  X     Y
  glVertex2f(0.5, 0.5)
  glVertex2f(-0.5, 0.5)
  # Pintamos puntos utilizando random
  glColor3fv([1, 1, 0])
  for _ in range(600):
    x = randrange(-600, 600) / 600
    y = randrange(-600, 600) / 600
    r, g, b = random(), random(), random()
    #glColor3fv([r, g, b])
    #glVertex2f(-random(), ramdom())
    glVertex2f(x, y)
  glEnd()

def Parabola():
  glBegin(GL_POINTS)
  glColor3fv([0, 1, 0])
  x = -1
  for _ in range(600):
    y = x**2
    c = [random(), random(), random()]
    glColor3fv(c)
    glVertex2f(x, y)
    glVertex2f(x, -y)
    x += 1 / 300
  glEnd()
def Linea():
  glBegin(GL_POINTS)
  x = -1
  for _ in range(600):
    y = x
    glColor3fv([random(), random(),random()])
    glVertex2f(x, y)
    glVertex2f(x+0.2, y)
    x+= 1 / 300
  glEnd()
Principal()