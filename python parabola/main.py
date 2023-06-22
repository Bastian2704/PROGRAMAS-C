import math
import matplotlib.pyplot as plt
import numpy as np

def dibujar_parabola(radio_planeta, gravedad, angulo_lanzamiento, velocidad_inicial):
    tiempo_vuelo = (2 * velocidad_inicial * math.sin(angulo_lanzamiento)) / gravedad
    alcance = (velocidad_inicial**2 * math.sin(2 * angulo_lanzamiento)) / gravedad

    tiempo = np.linspace(0, tiempo_vuelo, num=100)
    x = (velocidad_inicial * math.cos(angulo_lanzamiento) * tiempo)
    y = (velocidad_inicial * math.sin(angulo_lanzamiento) * tiempo) - (0.5 * gravedad * tiempo**2)

    plt.plot(x, y)
    plt.xlabel("Distancia (m)")
    plt.ylabel("Altura (m)")
    plt.title("Parábola de lanzamiento en el planeta")
    plt.axis('equal')
    plt.grid(True)
    plt.show()

# Obtener los valores del usuario
radio = float(input("Ingrese el radio del planeta (m): "))
gravedad = float(input("Ingrese la gravedad del planeta (m/s^2): "))
angulo = math.radians(float(input("Ingrese el ángulo de lanzamiento (grados): ")))
velocidad = float(input("Ingrese la velocidad inicial (m/s): "))

# Llamar a la función para dibujar la parábola
dibujar_parabola(radio, gravedad, angulo, velocidad)
