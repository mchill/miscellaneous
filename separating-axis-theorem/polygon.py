"""
Represents a two-dimensional polygon with n edges.
"""

class Polygon(object):
    """Represents a two-dimensional polygon with n edges."""

    def __init__(self, *args):
        """Initialize a polygon, given its vertices. Pre-calculate its edges for efficiency."""
        self.vertices = args
        self.edges = [args[0] - args[len(args) - 1]]

        last_vertex = args[0]
        for vertex in self.vertices[1:]:
            self.edges.append(vertex - last_vertex)
            last_vertex = vertex

    def move(self, velocity):
        """Move the polygon the specified velocity."""
        self.vertices = [vertex + velocity for vertex in self.vertices]

    def is_colliding(self, other):
        """Detect if this polygon is colliding with the passed polygon."""
        for edge in self.edges:
            check = 'x_pos' if abs(edge.x_pos) > abs(edge.y_pos) else 'y_pos'

            self_projections = [getattr(vertex.project_onto(edge), check) for vertex in self.vertices]
            other_projections = [getattr(vertex.project_onto(edge), check) for vertex in other.vertices]

            if min(self_projections) >= max(other_projections) or min(other_projections) >= max(self_projections):
                return False

        return True

    def draw(self, canvas, color):
        """Draw the polygon on the given canvas."""
        vertices = [[vertex.x_pos, vertex.y_pos] for vertex in self.vertices]
        canvas.create_polygon(vertices, fill='', outline=color)
