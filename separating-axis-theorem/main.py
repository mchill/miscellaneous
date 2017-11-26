#!/usr/bin/python
"""Detect and visualize collision using the Separating Axis Theorem."""

import argparse
from threading import Thread
import Tkinter
from polygon import Polygon
from vector  import Vector


def main():
    """Constructs the canvas, binds keyboard events, and starts the main update loop."""
    polygons = get_polygons()

    root = Tkinter.Tk()
    canvas = Tkinter.Canvas(root)
    canvas.pack()

    root.bind('<Left>', polygons[0].move_left)
    root.bind('<Right>', polygons[0].move_right)
    root.bind('<Up>', polygons[0].move_up)
    root.bind('<Down>', polygons[0].move_down)

    loop_thread = Thread(target=loop, args=(root, canvas, polygons))
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


def loop(root, canvas, polygons):
    """Draw the polygons on a canvas and detect collision."""
    canvas.delete('all')

    for polygon in polygons:
        polygon.draw(canvas)
    print polygons[0].is_colliding(polygons[1])

    root.after(50, loop, root, canvas, polygons)


if __name__ == "__main__":
    main()
