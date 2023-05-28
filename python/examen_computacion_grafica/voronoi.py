import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import Voronoi, voronoi_plot_2d
# Generar puntos aleatorios
np.random.seed(0)
points = np.random.rand(50, 2)
# Calcular el diagrama de Voronoi
vor = Voronoi(points)
# Graficar el diagrama de Voronoi
voronoi_plot_2d(vor, show_vertices=False, line_colors='k', line_width=0.5, line_alpha=0.6)
# Colorear cada región con un color diferente
for region in vor.regions:
  if len(region) > 0 and -1 not in region:
    polygon = [vor.vertices[i] for i in region]
    plt.fill(*zip(*polygon), alpha=0.4)
# Configuraciones adicionales del gráfico
plt.xlim(vor.min_bound[0] - 0.1, vor.max_bound[0] + 0.1)
plt.ylim(vor.min_bound[1] - 0.1, vor.max_bound[1] + 0.1)
plt.gca().set_aspect('equal', adjustable='box')
plt.axis('off')
# Mostrar el gráfico
plt.show()