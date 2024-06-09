import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
import datetime
import time
from mpl_toolkits.basemap import Basemap
# Convierte el archivo .xlsx a .csv
# read_file = pd.read_excel("D:\Temp\IGP_datos_sismicos (1).xlsx")
# read_file.to_csv("D:\Temp\IGP_datos_sismicos (1).csv", index = None, header = True)
# Lee el archivo .csv generado anteriormente
data = pd.read_csv("./IGP_datos_sismicos (1).csv")
# Renombrar variables (nombre de la columna) del archivo .csv
data = data.rename(columns = {
  data.columns[0]: "fecha_UTC",
  data.columns[1]: "hora_UTC",
  data.columns[2]: "latitud",
  data.columns[3]: "longitud",
  data.columns[4]: "profundidad_km",
  data.columns[5]: "magnitud_M",
}, errors = "raise")
# Convierte la fecha y tiempo a Unix time
timestamp = []
for d, t in zip(data["fecha_UTC"],  data["hora_UTC"]):
  try:
    ts = datetime.datetime.strptime(d + ' ' + t, '%d/%m/%Y %H:%M:%S')
    timestamp.append(time.mktime(ts.timetuple()))
  except ValueError:
    # print("ValueError")
    timestamp.append("ValueError")
timeStamp = pd.Series(timestamp)
data["Marca de tiempo"] = timeStamp.values
final_data = data.drop(["fecha_UTC", "hora_UTC"], axis = 1)
final_data = final_data[final_data["Marca de tiempo"] != "ValueError"]
# Visualización de lugares con mayor frecuencia de eventos sísmicos
m = Basemap(projection = "merc", llcrnrlat = -21, urcrnrlat = 0.6, llcrnrlon = -85, urcrnrlon = -65, resolution = 'c')
longitudes = data["longitud"].tolist()
latitudes = data["latitud"].tolist()
x, y = m(longitudes, latitudes)
fig = plt.figure(figsize = (8, 6))
plt.title("Todas las zonas afectadas")
m.plot(x, y, "o", markersize = 2, color = "blue")
m.drawcoastlines()
m.fillcontinents(color = "coral", lake_color = "aqua")
m.drawmapboundary()
m.drawcountries()
m.drawstates()
# m.bluemarble()
plt.show()