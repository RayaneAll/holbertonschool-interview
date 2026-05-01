#!/usr/bin/python3
"""Rainwater retention module."""


def rain(walls):
    """Return the total amount of rainwater retained by the walls."""
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = walls[left]
    right_max = walls[right]
    water = 0

    while left < right:
        if left_max <= right_max:
            left += 1
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
        else:
            right -= 1
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]

    return water
