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

    def move_left(self, _):
        """Move the polygon left."""
        self.move(-1, 0)

    def move_right(self, _):
        """Move the polygon right."""
        self.move(1, 0)

    def move_up(self, _):
        """Move the polygon up."""
        self.move(0, -1)

    def move_down(self, _):
        """Move the polygon down."""
        self.move(0, 1)

    def move(self, delta_x, delta_y):
        """Move the polygon the specified horizontal and vertical distances."""
        for vertex in self.vertices:
            vertex.x_pos += delta_x
            vertex.y_pos += delta_y

    def is_colliding(self, other):
        """Detect if this polygon is colliding with the passed polygon."""
        for edge in self.edges:
            first_projections = []
            second_projections = []

            for vertex in self.vertices:
                first_projections.append(len(vertex.project_onto(edge)))

            for vertex in other.vertices:
                second_projections.append(len(vertex.project_onto(edge)))

            if (min(first_projections) >= max(second_projections) or
                    min(second_projections) >= max(first_projections)):
                return False

        return True

    def draw(self, canvas):
        """Draw the polygon on the given canvas."""
        vertices = [[vertex.x_pos, vertex.y_pos] for vertex in self.vertices]
        canvas.create_polygon(vertices, fill='', outline='black')
