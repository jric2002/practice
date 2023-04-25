import pygame
pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True
dt = 0
ball_position = pygame.Vector2(screen.get_width()/2, screen.get_height()/2)
speed = 5
right = True
left = False
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
  pygame.draw.circle(screen, "black", ball_position, 20)
  keys = pygame.key.get_pressed()
  if right:
    ball_position.x += speed
  if (ball_position.x + 20) > screen.get_width():
    right = False
    left = True
  if left:
    ball_position.x -= speed
  if (ball_position.x - 20) < 0:
    left = False
    right = True
  if keys[pygame.K_a]:
    ball_position.x -= speed
  if keys[pygame.K_d]:
    ball_position.x += speed
  if keys[pygame.K_w]:
    ball_position.y -= speed
  if keys[pygame.K_s]:
    ball_position.y += speed
  pygame.display.flip()
  clock.tick(60)
pygame.quit()