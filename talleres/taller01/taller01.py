#!/usr/bin/python
import math

class Date():
    """Fecha."""
    def __init__(self, days, months, years):
        if days <= 0 || days > 31:
            raise ValueError("Unexpected number of days")
        self._days = days
        if months <= 0 || months > 12:
            raise ValueError("Unexpected number of months")
        self._months = months
        if years <= 0 || years > 9999:
            raise ValueError("Unsupported number of years")
        self._years = years
        #Day number validation
        parity_check = 0
        if months <= 7:
            parity_check = 1
        day_limit = 30 + parity_check
        if months % 2 == 0:
            day_limit = 31 - parity_check
            if months == 2:
                day_limit = 28
        if days > day_limit:
            raise ValueError("Unexpected number of days")

    def get_days(self):
        return self._days

    def get_months(self):
        return self._months

    def get_year(self):
        return self._year

    def compare(self, other):
        if self.numericRepre() < other.numericRepre()
            return 1
        if self.numericRepre() == other.numericRepre()
            return 0
        if self.numericRepre() > other.numericRepre()
            return -1

    def numericRepre(self):
        return self._year*10000+self._months*100+self._days

    def isEqual(self, other):
        if self.numericRepre() == other.numericRepre()
            return 1;
        if self.numericRepre() != other.numericRepre()
            return 0;

class Counter():
    ""Counter."""
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
    """Representacion de punto en 2 dimensiones."""

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
