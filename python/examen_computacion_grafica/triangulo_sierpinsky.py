import turtle
def dibujar_triangulo_sierpinski(t, profundidad, size):
  if profundidad == 0:
    for _ in range(3):
      t.forward(size)
      t.left(120)
  else:
    dibujar_triangulo_sierpinski(t, profundidad - 1, size / 2)
    t.forward(size / 2)
    dibujar_triangulo_sierpinski(t, profundidad - 1, size / 2)
    t.backward(size / 2)
    t.left(60)
    t.forward(size / 2)
    t.right(60)
    dibujar_triangulo_sierpinski(t, profundidad - 1, size / 2)
    t.left(60)
    t.backward(size / 2)
    t.right(60)
# Configuraciones de la ventana de dibujo
window = turtle.Screen()
window.title("Triángulo de Sierpinski")
window.bgcolor("white")
# Configuraciones de la tortuga
t = turtle.Turtle()
t.speed(0)
t.penup()
t.goto(-200, -200)
t.pendown()
# Parámetros del triángulo de Sierpinski
profundidad = 4
size = 400
# Dibujar el triángulo de Sierpinski
dibujar_triangulo_sierpinski(t, profundidad, size)
# Ocultar la tortuga
t.hideturtle()
# Mantener la ventana abierta
turtle.done()