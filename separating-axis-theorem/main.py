#!/usr/bin/python
"""Detect and visualize collision using the Separating Axis Theorem."""

import argparse
from threading import Thread
import Tkinter
from polygon import Polygon
from vector import Vector


class DIRECTION(dict):
    """Define the directions that a polygon can move in 2D space."""
    LEFT = Vector(-1, 0)
    RIGHT = Vector(1, 0)
    UP = Vector(0, -1)
    DOWN = Vector(0, 1)

    def __getattr__(self, name):
        """Allow dot notation attribute access."""
        return self[name]

def main():
    """Constructs the canvas, binds keyboard events, and starts the main update loop."""
    polygons = get_polygons()
    selected_polygon = [polygons[0]]
    velocity = Vector(0, 0)

    root = Tkinter.Tk()
    canvas = Tkinter.Canvas(root)
    canvas.pack()
    canvas.focus_set()

    root.bind('<Escape>', lambda _: root.destroy())
    root.bind('<Tab>', lambda _: change_selected_polygon(polygons, selected_polygon))
    root.bind('<KeyPress-Left>', lambda _: accelerate(velocity, DIRECTION.LEFT))
    root.bind('<KeyRelease-Left>', lambda _: accelerate(velocity, DIRECTION.RIGHT))
    root.bind('<KeyPress-Right>', lambda _: accelerate(velocity, DIRECTION.RIGHT))
    root.bind('<KeyRelease-Right>', lambda _: accelerate(velocity, DIRECTION.LEFT))
    root.bind('<KeyPress-Up>', lambda _: accelerate(velocity, DIRECTION.UP))
    root.bind('<KeyRelease-Up>', lambda _: accelerate(velocity, DIRECTION.DOWN))
    root.bind('<KeyPress-Down>', lambda _: accelerate(velocity, DIRECTION.DOWN))
    root.bind('<KeyRelease-Down>', lambda _: accelerate(velocity, DIRECTION.UP))

    loop_thread = Thread(target=loop, args=(root, canvas, polygons, selected_polygon, velocity))
    loop_thread.start()
    root.mainloop()
    loop_thread.join()


def get_polygons():
    """Parse the input file and construct the polygons."""
    parser = argparse.ArgumentParser(description='Detect polygonal collisions.')
    parser.add_argument('file', help='a file containing polygon data')
    args = parser.parse_args()

    with open(args.file) as input_file:
        lines = input_file.readlines()

    polygons = []
    for line in [line.strip().split(' ') for line in lines]:
        vertices = [[int(pos) for pos in vertex.split(',')] for vertex in line]
        polygons.append(Polygon(*[Vector(*vertex) for vertex in vertices]))
    return polygons


def change_selected_polygon(polygons, selected_polygon):
    """Select the next polygon in the polygon list. The selected polygon gets moved by the arrow keys."""
    selected_polygon[0] = polygons[(polygons.index(selected_polygon[0]) + 1) % len(polygons)]


def accelerate(velocity, direction):
    """Add the given acceleration vector to the current velocity vector."""
    velocity.add(direction)


def loop(root, canvas, polygons, selected_polygon, velocity):
    """Draw the polygons on a canvas and detect collision."""
    canvas.delete('all')
    selected_polygon[0].move(velocity)

    colliding = polygons[0].is_colliding(polygons[1])
    colliding_text = 'Collision detected!' if colliding else 'No collision detected'
    colliding_color = 'red' if colliding else 'black'
    canvas.create_text(5, 5, text=colliding_text, fill=colliding_color, anchor=Tkinter.NW)

    for polygon in polygons:
        color = 'red' if polygon == selected_polygon[0] else 'black'
        polygon.draw(canvas, color)

    root.after(50, loop, root, canvas, polygons, selected_polygon, velocity)


if __name__ == "__main__":
    main()
