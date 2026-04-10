#!/usr/bin/python3
"""N Queens puzzle solver."""

import sys


def solve_nqueens(n, row, cols, diag1, diag2, positions):
    """Backtracking solver that prints each valid solution."""
    col = 0

    if row == n:
        print([[i, positions[i]] for i in range(n)])
        return

    while col < n:
        d1 = row - col
        d2 = row + col
        if col not in cols and d1 not in diag1 and d2 not in diag2:
            positions[row] = col
            cols.add(col)
            diag1.add(d1)
            diag2.add(d2)

            solve_nqueens(n, row + 1, cols, diag1, diag2, positions)

            cols.remove(col)
            diag1.remove(d1)
            diag2.remove(d2)
        col += 1


def parse_n():
    """Validate and return the board size from argv."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n


if __name__ == "__main__":
    size = parse_n()
    solve_nqueens(size, 0, set(), set(), set(), [-1] * size)
