from tkinter import *
import math
ee = 0.05
diametro = 300
ancho = 800
alto = 600
vertices = 3
def obtener_coordenadas(od, cx, cy, vertices=3, offset=0):
  angulo = 2 * math.pi / vertices
  return [[math.cos((angulo * i) + (offset * math.pi / 180)) * od / 2 + cx, math.sin((angulo * i) + (offset * math.pi / 180)) * od / 2 + cy] for i in range(vertices)]
def dibujar_poligono_interpolado(puntos, color, rango):
  puntos.append(puntos[0])
  for i in range(rango):
    for j in range(len(puntos) - 1):
      dibujar(j, puntos, color[j % vertices])
    puntos = [[ee * puntos[i][0] + (1 - ee) * puntos[i + 1][0], ee * puntos[i][1] + (1 - ee) * puntos[i + 1][1]] for i in range(len(puntos) - 1)]
    puntos.append(puntos[0])
    color.append(color.pop(0))
def dibujar(i, p, c):
  canvas.create_line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1], fill=c)
root = Tk()
root.title("Polígono de lineas")
canvas = Canvas(width=ancho, height=alto, bg='black')
color = ["red", "yellow", "white"]
pt1 = obtener_coordenadas(diametro, (ancho / 2) - (diametro / 2), alto / 2, vertices, 0)
pt3 = obtener_coordenadas(diametro, (ancho / 2) - (diametro / 4), (alto / 2) - ((diametro / 4) * math.sqrt(3)), vertices, 180)
pt4 = obtener_coordenadas(diametro, (ancho / 2) + (diametro / 4), (alto / 2) - ((diametro / 4) * math.sqrt(3)), vertices, 120)
pt2 = obtener_coordenadas(diametro, (ancho / 2) + (diametro / 2), alto / 2, vertices, 60)
pt5 = obtener_coordenadas(diametro, (ancho / 2) + (diametro / 4), (alto / 2) + ((diametro / 4) * math.sqrt(3)), vertices, 120)
pt6 = obtener_coordenadas(diametro, (ancho / 2) - (diametro / 4), (alto / 2) + ((diametro / 4) * math.sqrt(3)), vertices, 60)

dibujar_poligono_interpolado(pt1, color, 50)
dibujar_poligono_interpolado(pt2, color, 50)
dibujar_poligono_interpolado(pt3, color, 50)
dibujar_poligono_interpolado(pt4, color, 50)
dibujar_poligono_interpolado(pt5, color, 50)
dibujar_poligono_interpolado(pt6, color, 50)

canvas.pack()
mainloop()