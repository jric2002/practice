import pygame
pygame.init()
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()
running = True
dt = 0
ball_position = pygame.Vector2(screen.get_width()/2, screen.get_height()/2)
speed_x = speed_y = 5
ball_radius = 20
while running:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False
    """ if event.type == pygame.KEYDOWN:
      if event.key == pygame.K_a:
        ball_position.x -= speed
      if event.key == pygame.K_d:
        ball_position.x += speed
      if event.key == pygame.K_w:
        ball_position.y -= speed
      if event.key == pygame.K_s:
        ball_position.y += speed """
  screen.fill("yellow")
  pygame.draw.circle(screen, "black", ball_position, ball_radius)
  keys = pygame.key.get_pressed()
  if (ball_position.x + ball_radius) > screen.get_width() or ball_position.x < ball_radius:
    speed_x *= -1
  if (ball_position.y + ball_radius) > screen.get_height() or ball_position.y < ball_radius:
    speed_y *= -1
  ball_position.x += speed_x
  ball_position.y += speed_y
  """ if keys[pygame.K_a]:
    ball_position.x -= speed_x
  if keys[pygame.K_d]:
    ball_position.x += speed_x
  if keys[pygame.K_w]:
    ball_position.y += speed_y
  if keys[pygame.K_s]:
    ball_position.y -= speed_y """
  pygame.display.flip()
  clock.tick(60)
pygame.quit()