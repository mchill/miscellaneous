"""Represents a two-dimensional vector."""

class Vector(object):
    """Represents a two-dimensional vector."""

    def __init__(self, x_pos, y_pos):
        """Initialize the horizontal and vertical coordinates of the vector."""
        self.x_pos = x_pos
        self.y_pos = y_pos

    def project_onto(self, other):
        """Return the projection of this vector onto the passed vector."""
        dot_product = self.x_pos * other.x_pos + self.y_pos * other.y_pos
        length_squared = other.x_pos ** 2 + other.y_pos ** 2
        return other * (dot_product / float(length_squared))

    def __sub__(self, other):
        """Overload vector subtraction."""
        return Vector(self.x_pos - other.x_pos, self.y_pos - other.y_pos)

    def __rsub__(self, other):
        """Overload vector subtraction."""
        return Vector(other.x_pos - self.x_pos, other.y_pos - self.y_pos)

    def __mul__(self, constant):
        """Overload scalar multiplication."""
        return Vector(self.x_pos * constant, self.y_pos * constant)

    def __rmul__(self, constant):
        """Overload scalar multiplication."""
        return self.__mul__(constant)

    def __str__(self):
        """"Print the vector"""
        return '({}, {})'.format(self.x_pos, self.y_pos)
