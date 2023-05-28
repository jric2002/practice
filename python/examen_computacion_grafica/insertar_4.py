import pygame
import random
import math
pygame.init()
# Variables generales
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()
running = True
speed_x = speed_y = 3
radius = 30
class Ball():
  def __init__(self, radius, pos, speed, direction, color):
    self.radius = radius
    self.pos = pos
    self.speed = speed
    self.direction = direction
    self.color = color
balls = []
coefficient = 4
for i in range(0, 4):
  r = coefficient * radius
  s = True
  while s:
    x = random.randint(r, screen.get_width() - r)
    y = random.randint(r, screen.get_height() - r)
    s = False
    for i in range(0, len(balls)):
      d = math.sqrt(math.pow((balls[i].pos.x - x), 2) + pow((balls[i].pos.y - y), 2))
      if ((d - balls[i].radius) <= r):
        s = True
        break
  color = dict(r = random.randint(0, 255), g = random.randint(0, 255), b = random.randint(0, 255))
  balls.append(Ball(r, pygame.Vector2(x, y), pygame.Vector2(speed_x, speed_y), pygame.Vector2(1, 1), pygame.Color(color.get("r"), color.get("g"), color.get("b"))))
  coefficient /= 2
while running:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False
  screen.fill(pygame.Color(255, 255, 255))
  temp_balls = list()
  for i in range(0, len(balls)):
    temp_balls.append(pygame.draw.circle(screen, balls[i].color, balls[i].pos, balls[i].radius))
  for i in range(0, len(temp_balls)):
    for j in range(i + 1, len(balls)):
      d = math.sqrt(math.pow((balls[j].pos.x - balls[i].pos.x), 2) + pow((balls[j].pos.y - balls[i].pos.y), 2))
      if ((d - balls[i].radius) <= balls[j].radius):
        tdx = balls[i].direction.x
        tdy = balls[i].direction.y
        balls[i].direction.x = balls[j].direction.x
        balls[i].direction.y = balls[j].direction.y
        balls[j].direction.x = tdx
        balls[j].direction.y = tdy
        copy_ball1 = balls[i]
        copy_ball2 = balls[j]
        if (i < j):
          balls.pop(i)
          balls.pop(j - 1)
        else:
          balls.pop(j)
          balls.pop(i - 1)
        if (copy_ball1.radius % radius == 0):
          nuevo_radio = (copy_ball1.radius / 2)
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball1.pos.x, copy_ball1.pos.y), copy_ball1.speed, copy_ball1.direction, balls[i].color))
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball1.pos.x, copy_ball1.pos.y), copy_ball1.speed, copy_ball1.direction, copy_ball1.color))
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball1.pos.x, copy_ball1.pos.y), copy_ball1.speed, copy_ball1.direction, balls[i].color))
        if (copy_ball2.radius % radius == 0):
          nuevo_radio = (copy_ball2.radius / 2)
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball2.pos.x, copy_ball2.pos.y), copy_ball2.speed, copy_ball2.direction, copy_ball2.color))
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball2.pos.x, copy_ball2.pos.y), copy_ball2.speed, copy_ball2.direction, copy_ball2.color))
          balls.append(Ball(nuevo_radio, pygame.Vector2(copy_ball2.pos.x, copy_ball2.pos.y), copy_ball2.speed, copy_ball2.direction, copy_ball2.color))
        break
  for i in range(0, len(balls)):
    if (balls[i].pos.x + balls[i].radius) > screen.get_width() or balls[i].pos.x < balls[i].radius:
      balls[i].direction.x *= -1
    if (balls[i].pos.y + balls[i].radius) > screen.get_height() or balls[i].pos.y < balls[i].radius:
      balls[i].direction.y *= -1
    balls[i].pos.x += balls[i].speed.x * balls[i].direction.x
    balls[i].pos.y += balls[i].speed.y * balls[i].direction.y
  pygame.display.flip()
  clock.tick(60)
pygame.quit()