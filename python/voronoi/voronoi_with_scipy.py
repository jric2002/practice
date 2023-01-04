from scipy.spatial import Voronoi, voronoi_plot_2d
import matplotlib.pyplot as plt
import numpy as np
points = np.array([[0, 1], [2, 1], [1, 3]])
vor = Voronoi(points)
fig = voronoi_plot_2d(vor)
plt.show()