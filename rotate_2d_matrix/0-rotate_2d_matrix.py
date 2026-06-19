#!/usr/bin/python3
"""Rotate 2D matrix in-place."""


def rotate_2d_matrix(matrix):
    """Rotate an n x n matrix by 90 degrees clockwise in-place.

    Args:
        matrix (list[list[int]]): The matrix to rotate.
    """
    n = len(matrix)

    for i in range(n // 2):
        for j in range(i, n - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = temp
