#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing Pascal's triangle.
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        previous = triangle[-1]
        row = [1]

        for j in range(len(previous) - 1):
            row.append(previous[j] + previous[j + 1])

        row.append(1)
        triangle.append(row)

    return triangle
