# Author: José Rodolfo (jric2002)
import matplotlib.pyplot as plt
datos = []
datos.append([250, 1.003])
datos.append([300, 1.005])
datos.append([350, 1.008])
datos.append([400, 1.013])
datos.append([450, 1.020])
datos.append([500, 1.029])
datos.append([550, 1.040])
datos.append([600, 1.051])
datos.append([650, 1.063])
datos.append([700, 1.075])
datos.append([750, 1.087])
datos.append([800, 1.099])
datos.append([900, 1.121])
datos.append([1000, 1.142])
datos.sort(key=lambda x : x[0]) # Ordena los datos en base a X
print("Datos")
print("-" * 6)
print(datos)
x = float(input("Ingresa un valor para 'x': "))
print()
y = x1 = y1 = x2 = y2 = 0
for i in range(0, len(datos)): # Busca (x1, y1) y (x2, y2)
  if (datos[i][0] > x):
    x2 = datos[i][0]
    y2 = datos[i][1]
    x1 = datos[i - 1][0]
    y1 = datos[i - 1][1]
    break
y = (((x - x1) / (x2 - x1)) * (y2 - y1)) + y1 # Formula para hallar el valor de Y
print("x1: " + str(x1), "y1: " + str(y1), sep='\t')
print("x2: " + str(x2), "y2: " + str(y2), sep='\t')
print("Valor de 'y' es: " + str(y))
plt_fig = plt.figure(figsize=(12, 5)) # Establecer las dimensiones
plt.subplot(1, 2, 1) # Posición del 1er grafico
plt.plot([x[0] for x in datos], [y[1] for y in datos], '-', color="blue", label="Curva Real") # Grafica con todos los datos
plt.title("Grafica 1")
plt.ylabel("Calor especifico")
plt.xlabel("Temperatura")
plt.legend()
plt.grid(color="black", linestyle='--')
plt.subplot(1, 2, 2) # Posición del 2do grafico
plt.plot([x1, x, x2], [y1, y, y2], '-', marker='o', mec='g', mfc='g', color="orange", label="Recta Aproximada") # Resultado de usar interpolación lineal
plt.xlim((2 * x1) - x, (2 * x2) - x)
plt.ylim((2 * y1) - y, (2 * y2) - y)
plt.title("Grafica 2")
plt.ylabel("Calor especifico")
plt.xlabel("Temperatura")
plt.suptitle("Interpolación Lineal")
plt.legend()
plt.grid(color="black", linestyle='--')
plt.show()