#!/usr/bin/python3
"""Lockboxes problem solution."""


def canUnlockAll(boxes):
    """Determine if all boxes can be opened using available keys.

    Args:
        boxes (list[list[int]]): List of boxes, each containing keys.

    Returns:
        bool: True if every box can be opened, otherwise False.
    """
    if not isinstance(boxes, list):
        return False

    total_boxes = len(boxes)
    if total_boxes == 0:
        return False

    opened = set([0])
    keys = [0]

    while keys:
        box_idx = keys.pop()
        if box_idx >= total_boxes:
            continue
        for key in boxes[box_idx]:
            valid_key = isinstance(key, int) and 0 <= key < total_boxes
            if valid_key and key not in opened:
                opened.add(key)
                keys.append(key)

    return len(opened) == total_boxes
