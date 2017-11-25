"""Detect and visualize collision using the Separating Axis Theorem."""

from polygon import Polygon
from vector  import Vector


def is_colliding(first, second):
    """Detect if the first and second polygons are colliding."""
    for edge in first.edges:
        first_projections = []
        second_projections = []

        for vertex in first.vertices:
            first_projections.append(len(vertex.project_onto(edge)))

        for vertex in second.vertices:
            second_projections.append(len(vertex.project_onto(edge)))

        if (min(first_projections) >= max(second_projections) or
                min(second_projections) >= max(first_projections)):
            return False

    return True


FIRST = Polygon(
    Vector(0, 0),
    Vector(0, 2),
    Vector(2, 2),
    Vector(2, 0)
)
SECOND = Polygon(
    Vector(1, 0),
    Vector(1, 2),
    Vector(3, 2),
    Vector(3, 0)
)

print is_colliding(FIRST, SECOND)
