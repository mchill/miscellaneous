"""Detect and visualize collision using the Separating Axis Theorem."""

import argparse
from polygon import Polygon
from vector  import Vector


def get_polygons():
    """Parse the input file and construct the polygons."""
    parser = argparse.ArgumentParser(description='Detect polygonal collisions.')
    parser.add_argument('file', help='a file containing polygon data')
    args = parser.parse_args()

    with open(args.file) as file:
        lines = file.readlines()

    polygons = []
    for line in [line.strip().split(' ') for line in lines]:
        vertices = [[int(pos) for pos in vertex.split(',')] for vertex in line]
        polygons.append(Polygon(*[Vector(*vertex) for vertex in vertices]))
    return polygons


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


polygons = get_polygons()
print is_colliding(*polygons)
