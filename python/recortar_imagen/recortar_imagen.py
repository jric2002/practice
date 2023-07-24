import cv2
import numpy as np
# Cargar las dos imágenes
img1 = cv2.imread("./img/rs-rain-1.jpg")
img2 = cv2.imread("./img/rs-rain-2.jpg")
# Convertir las imágenes a escala de grises
gray1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
gray2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
# Detectar los puntos clave y calcular los descriptores con el algoritmo SIFT
sift = cv2.SIFT_create()
kp1, des1 = sift.detectAndCompute(gray1, None)
kp2, des2 = sift.detectAndCompute(gray2, None)
# Emparejar los puntos clave y obtener una homografía
bf = cv2.BFMatcher()
matches = bf.knnMatch(des1, des2, k=2)
good_matches = []
for m, n in matches:
  if m.distance < 0.75*n.distance:
    good_matches.append(m)
src_pts = np.float32([ kp1[m.queryIdx].pt for m in good_matches ]).reshape(-1,1,2)
dst_pts = np.float32([ kp2[m.trainIdx].pt for m in good_matches ]).reshape(-1,1,2)
M, mask = cv2.findHomography(src_pts, dst_pts, cv2.RANSAC, 5.0)
# Calcular las dimensiones de la imagen panorámica
h1, w1 = img1.shape[:2]
h2, w2 = img2.shape[:2]
pts1 = np.float32([[0,0],[0,h1],[w1,h1],[w1,0]]).reshape(-1,1,2)
pts2 = np.float32([[0,0],[0,h2],[w2,h2],[w2,0]]).reshape(-1,1,2)
pts1_ = cv2.perspectiveTransform(pts1, M)
pts = np.concatenate((pts1_, pts2), axis=0)
[xmin, ymin] = np.int32(pts.min(axis=0).ravel() - 0.5)
[xmax, ymax] = np.int32(pts.max(axis=0).ravel() + 0.5)
# Alinear las imágenes y recortar la imagen panorámica
M[2][0] += -xmin
M[2][1] += -ymin
result = cv2.warpPerspective(img1, M, (xmax-xmin, ymax-ymin))
result[-ymin:h2-ymin,-xmin:w2-xmin] = img2
# Mostrar la imagen resultante
cv2.imshow('Resultado', result)
cv2.waitKey()
cv2.destroyAllWindows()