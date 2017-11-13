#!/usr/bin/python
"""
Represents a two-dimensional vector.
"""

class Vector(object):
    """Represents a two-dimensional vector."""

    def __init__(self, x, y):
        """Initialize the horizontal and vertical coordinates of the vector."""
        self.x = x
        self.y = y

    def project_onto(self, other):
        """Return the projection of this vector onto the passed vector."""
        dot_product = self.x * other.x + self.y * other.y
        length_squared = other.x ** 2 + other.y ** 2
        return other * (dot_product / float(length_squared))

    def __sub__(self, other):
        """Overload vector subtraction."""
        return Vector(self.x - other.x, self.y - other.y)

    def __rsub__(self, other):
        """Overload vector subtraction."""
        return Vector(other.x - self.x, other.y - self.y)

    def __mul__(self, constant):
        """Overload scalar multiplication."""
        return Vector(self.x * constant, self.y * constant)

    def __rmul__(self, constant):
        """Overload scalar multiplication."""
        return self.__mul__(constant)

    def __str__(self):
        """"Print the vector"""
        return '({}, {})'.format(self.x, self.y)
