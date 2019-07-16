#!/usr/bin/python
import math

class Counter():
    """counter."""
    def __init__(self):

    def increase(self):


    def increments(self):


    def toString(self):


class Punto2D():
    """Representacion de punto en 2 dimenciones"""

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_x(self):
        return self.x


    def get_y(self):
        return self.y

    def radio_polar(self):
        return dist_euclidiana(selt, Punto2D(0,0))

    def angulo_polar(self):
        angulo = math.atan(self.y/self.x)
        return angulo

    def dist_euclidiana(self, Punto2D other):
        deltax = other.x - self.x
        deltay = other.y - self.y
        dist = math.sqrt(deltax**2 + deltay**2)
        return dist
