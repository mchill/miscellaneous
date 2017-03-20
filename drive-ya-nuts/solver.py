#!/usr/bin/python
"""
Solve the Drive Ya Nuts puzzle.
https://www.jaapsch.net/puzzles/circus.htm
"""

from copy import copy
from collections import deque


SIDES = 6
SPACES = 7


class Board(object):
    """Defines the game space, consists of spaces."""
    def __init__(self):
        """Initialize spaces and their connections."""
        spaces = [Space() for _ in range(SPACES)]
        self.spaces = spaces

        for index in range(SPACES - 1):
            self.connect(0, index, index + 1, (index + 3) % SIDES)
            self.connect(index + 1, (index + 2) % SIDES,
                         max((index + 2) % SPACES, 1), (index + 5) % SIDES)

    def connect(self, space1, side1, space2, side2):
        """Connect two spaces by their adjacent sides."""
        self.spaces[space1].connect(self.spaces[space2], side1, side2)
        self.spaces[space2].connect(self.spaces[space1], side2, side1)

    def place(self, piece):
        """
        Try to place the given piece in the next empty space. Tries 6 times,
        once for each rotation. Return False if the piece could not be placed.
        """
        space = next(space for space in self.spaces if space.piece is None)
        space.place(piece)

        for _ in range(SIDES):
            error = False

            for side, connection in enumerate(space.sides):
                adj = connection['adj']
                other_side = connection.get('other_side')

                if adj is None or adj.piece is None:
                    continue
                elif space.piece.sides[side] != adj.piece.sides[other_side]:
                    error = True
                    piece.rotate()
                    break

            if not error:
                return True

        space.empty()
        return False

    def remove(self):
        """Remove the most recently placed piece."""
        space = next(space for space in reversed(self.spaces) if space.piece is not None)
        space.empty()

    def is_full(self):
        "Determine whether or not every space on the board has a piece."""
        return all(space.piece is not None for space in self.spaces)

    def display(self):
        """Print the board with all placed pieces."""
        pc0, pc1, pc2, pc3, pc4, pc5, pc6 = [space.piece.sides for space in self.spaces]

        output = '          -----                      \n'
        output += '         /  {0}  \\                 \n'.format(pc1[0])
        output += '        / {0}   {1} \\              \n'.format(pc1[5], pc1[1])
        output += '  ----- \\ {0}   {1} / -----        \n'.format(pc1[4], pc1[2])
        output += ' /  {0}  \\ \\  {1}  / /  {2}  \\   \n'.format(pc6[0], pc1[3], pc2[0])
        output += '/ {0}   {1} \\ ----- / {2}   {3} \\ \n'.format(pc6[5], pc6[1], pc2[5], pc2[1])
        output += '\\ {0}   {1} / ----- \\ {2}   {3} / \n'.format(pc6[4], pc6[2], pc2[4], pc2[2])
        output += ' \\  {0}  / /  {1}  \\ \\  {2}  /   \n'.format(pc6[3], pc0[0], pc2[3])
        output += '  ----- / {0}   {1} \\ -----        \n'.format(pc0[5], pc0[1])
        output += '  ----- \\ {0}   {1} / -----        \n'.format(pc0[4], pc0[2])
        output += ' /  {0}  \\ \\  {1}  / /  {2}  \\   \n'.format(pc5[0], pc0[3], pc3[0])
        output += '/ {0}   {1} \\ ----- / {2}   {3} \\ \n'.format(pc5[5], pc5[1], pc3[5], pc3[1])
        output += '\\ {0}   {1} / ----- \\ {2}   {3} / \n'.format(pc5[4], pc5[2], pc3[4], pc3[2])
        output += ' \\  {0}  / /  {1}  \\ \\  {2}  /   \n'.format(pc5[3], pc4[0], pc3[3])
        output += '  ----- / {0}   {1} \\ -----        \n'.format(pc4[5], pc4[1])
        output += '        \\ {0}   {1} /              \n'.format(pc4[4], pc4[2])
        output += '         \\  {0}  /                 \n'.format(pc4[3])
        output += '          -----'

        print output


class Space(object):
    """A space in which a piece can be placed."""
    def __init__(self):
        """Define the sides of the space and set it to not have a piece."""
        self.sides = [{'adj': None} for _ in range(SIDES)]
        self.piece = None

    def connect(self, space, side, other_side):
        """Connect one of this space's sides to another space's side."""
        self.sides[side] = {'adj': space, 'other_side': other_side}

    def place(self, piece):
        """Place the given piece in this space."""
        self.piece = piece

    def empty(self):
        """Remove the piece in this space."""
        self.piece = None


class Piece(object):
    """A piece in the game."""
    def __init__(self, sides):
        """Define the side values."""
        self.sides = sides

    def rotate(self):
        """Rotate the piece once counterclockwise."""
        self.sides = self.sides[1:] + self.sides[:1]


def place(board, pieces):
    """Recursive function to find correct placement of pieces."""
    for _ in range(len(pieces)):
        piece = pieces.popleft()
        if board.place(piece):
            place(board, copy(pieces))
            if board.is_full():
                return
            board.remove()
        pieces.append(piece)


def solve():
    """Instantiate the board and pieces, and solve the puzzle."""
    board = Board()

    pieces = deque([
        Piece([1, 4, 3, 6, 5, 2]),
        Piece([1, 2, 3, 4, 5, 6]),
        Piece([1, 6, 4, 2, 5, 3]),
        Piece([1, 6, 5, 4, 3, 2]),
        Piece([1, 4, 6, 2, 3, 5]),
        Piece([1, 6, 2, 4, 5, 3]),
        Piece([1, 6, 5, 3, 2, 4])
    ])

    place(board, pieces)
    board.display()


if __name__ == '__main__':
    solve()
