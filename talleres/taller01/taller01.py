#!/usr/bin/python
import math

class Counter():
    """counter."""
    def __init__(self, id):
        self._id = id
        self._n = 0

    def increase(self):
        self._n = self._n +1

    def increments(self):
        return self._n

    def toString(self):
        return str(self._n)

class Punto2D():
    """Representacion de punto en 2 dimensiones"""

    def __init__(self, x, y):
        self._x = x
        self._y = y

    def get_x(self):
        return self._x


    def get_y(self):
        return self._y

    def radio_polar(self):
        return dist_euclidiana(selt, Punto2D(0,0))

    def angulo_polar(self):
        angulo = math.atan(self._y/self._x)
        return angulo

    def dist_euclidiana(self, Punto2D other):
        deltax = other.get_x() - self._x
        deltay = other.get_y() - self._y
        dist = math.sqrt(deltax**2 + deltay**2)
        return dist
