#!/usr/bin/python3
"""Minimum Operations module."""


def minOperations(n):
    """Return the minimum number of operations to reach n H characters."""
    if n < 2:
        return 0

    ops = 0
    factor = 2
    while n > 1:
        while n % factor == 0:
            ops += factor
            n //= factor
        factor += 1
    return ops
