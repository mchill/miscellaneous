#!/usr/bin/python
"""
Solve the Drive Ya Nuts puzzle.
https://www.jaapsch.net/puzzles/circus.htm
"""

import itertools


SIDES = 6
SPACES = 7


class Board:
    """Defines the game space, consists of spaces."""
    def __init__(self):
        """Initialize spaces and their connections."""
        spaces = [Space() for _ in range(SPACES)]
        self.spaces = spaces

        for index in range(SPACES - 1):
            next_space = (index + 2) % SPACES
            if next_space == 0:
                next_space = 1

            self.connect(spaces[0], index,
                         spaces[index + 1], (index + 3) % SIDES)
            self.connect(spaces[index + 1], (index + 2) % SIDES,
                         spaces[next_space], (index + 5) % SIDES)

    def connect(self, space1, side1, space2, side2):
        """Connect two spaces by their adjacent sides."""
        space1.connect(space2, side1, side2)
        space2.connect(space1, side2, side1)

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

                if adj == None or adj.piece == None:
                    continue
                elif space.piece.sides[side] != adj.piece.sides[other_side]:
                    error = True
                    piece.rotate()
                    break

            if not error:
                return True

        space.empty()
        return False

    def empty(self):
        """Remove piece from every space on the board."""
        for space in self.spaces:
            space.empty()

    def is_full(self):
        "Determine whether or not every space on the board has a piece."""
        return all(space.piece is not None for space in self.spaces)

    def display(self, spoiler=True):
        """Print the board with all placed pieces."""
        p0, p1, p2, p3, p4, p5, p6 = [space.piece.sides for space in self.spaces]
        if not spoiler:
            p0, p1, p2, p3, p4, p5, p6 = [[' ', ' ', ' ', ' ', ' ', ' ']] * 7

        output = '          -----                     \n'
        output += '         /  {0}  \\                \n'.format(p1[0])
        output += '        / {0}   {1} \\             \n'.format(p1[5], p1[1])
        output += '  ----- \\ {0}   {1} / -----       \n'.format(p1[4], p1[2])
        output += ' /  {0}  \\ \\  {1}  / /  {2}  \\  \n'.format(p6[0], p1[3], p2[0])
        output += '/ {0}   {1} \\ ----- / {2}   {3} \\\n'.format(p6[5], p6[1], p2[5], p2[1])
        output += '\\ {0}   {1} / ----- \\ {2}   {3} /\n'.format(p6[4], p6[2], p2[4], p2[2])
        output += ' \\  {0}  / /  {1}  \\ \\  {2}  /  \n'.format(p6[3], p0[0], p2[3])
        output += '  ----- / {0}   {1} \\ -----       \n'.format(p0[5], p0[1])
        output += '  ----- \\ {0}   {1} / -----       \n'.format(p0[4], p0[2])
        output += ' /  {0}  \\ \\  {1}  / /  {2}  \\  \n'.format(p5[0], p0[3], p3[0])
        output += '/ {0}   {1} \ ----- / {2}   {3} \\ \n'.format(p5[5], p5[1], p3[5], p3[1])
        output += '\\ {0}   {1} / ----- \\ {2}   {3} /\n'.format(p5[4], p5[2], p3[4], p3[2])
        output += ' \\  {0}  / /  {1}  \\ \\  {2}  /  \n'.format(p5[3], p4[0], p3[3])
        output += '  ----- / {0}   {1} \\ -----       \n'.format(p4[5], p4[1])
        output += '        \\ {0}   {1} /             \n'.format(p4[4], p4[2])
        output += '         \\  {0}  /                \n'.format(p4[3])
        output += '          -----'

        print output


class Space:
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
        """Remove the piece in this space and return it."""
        piece = self.piece
        self.piece = None
        return piece


class Piece:
    """A piece in the game."""
    def __init__(self, sides):
        """Define the side values."""
        self.sides = sides

    def rotate(self):
        """Rotate the piece once counterclockwise."""
        self.sides = self.sides[1:] + self.sides[:1]


def solve():
    """Instantiate the board and pieces, and solve the puzzle."""
    board = Board()

    permutations = itertools.permutations([
        Piece([1, 4, 3, 6, 5, 2]),
        Piece([1, 2, 3, 4, 5, 6]),
        Piece([1, 6, 4, 2, 5, 3]),
        Piece([1, 6, 5, 4, 3, 2]),
        Piece([1, 4, 6, 2, 3, 5]),
        Piece([1, 6, 2, 4, 5, 3]),
        Piece([1, 6, 5, 3, 2, 4])
    ])

    for permutation in permutations:
        board.empty()

        for index in range(SPACES):
            if not board.place(permutation[index]):
                break

        if board.is_full():
            board.display()
            break


if __name__ == '__main__':
    solve()
