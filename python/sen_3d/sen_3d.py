import numpy as np
import matplotlib.pyplot as plt
def funcion_seno_3d():
  fig = plt.figure(figsize=(10, 6))
  ax = fig.add_subplot(111, projection="3d")
  # Generar los puntos en el espacio 3D
  x = np.linspace(-10, 10, 100)
  y = np.linspace(-10, 10, 100)
  X, Y = np.meshgrid(x, y)
  Z = np.sin(np.sqrt((X**2)+ (Y**2)))
  # Crear un mapa de colores basado en la función seno
  colors = np.sin(Z)
  # Graficar la función seno en 3D
  ax.plot_surface(X, Y, Z, facecolors=plt.cm.jet(colors))
  # Configurar etiquetas y título
  ax.set_xlabel('X')
  ax.set_ylabel('Y')
  ax.set_zlabel('Z')
  ax.set_title('Función Seno en 3D')
  # Mostrar el gráfico
  plt.show()
# Llamar a la función para graficar el seno en 3D
funcion_seno_3d()