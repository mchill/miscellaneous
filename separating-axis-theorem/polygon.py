"""
Represents a two-dimensional polygon with n edges.
"""

class Polygon(object):
    """Represents a two-dimensional polygon with n edges."""

    def __init__(self, *args):
        """
        Initialize a polygon, given its vertices.
        Pre-calculate its edges for efficiency.
        """
        self.vertices = args
        self.edges = [args[0] - args[len(args) - 1]]

        last_vertex = args[0]
        for vertex in self.vertices[1:]:
            self.edges.append(vertex - last_vertex)
            last_vertex = vertex
