#!/usr/bin/python3
"""UTF-8 validation module."""


def validUTF8(data):
    """Return True if data is a valid UTF-8 encoding, else False."""
    expected = 0

    for byte in data:
        byte &= 0xFF

        if expected == 0:
            if (byte >> 7) == 0b0:
                continue
            if (byte >> 5) == 0b110:
                expected = 1
            elif (byte >> 4) == 0b1110:
                expected = 2
            elif (byte >> 3) == 0b11110:
                expected = 3
            else:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            expected -= 1

    return expected == 0
