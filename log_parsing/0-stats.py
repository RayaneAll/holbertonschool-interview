#!/usr/bin/python3
"""Read stdin line by line and compute log metrics."""
import sys


VALID_CODES = (200, 301, 400, 401, 403, 404, 405, 500)


def print_stats(total_size, code_counts):
    """Print current accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        count = code_counts.get(code, 0)
        if count:
            print("{}: {}".format(code, count))


def main():
    """Process stdin and print metrics every 10 lines."""
    total_size = 0
    line_count = 0
    code_counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()
            if len(parts) >= 2:
                try:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])
                except (ValueError, TypeError):
                    status_code = None
                    file_size = 0

                total_size += file_size
                if status_code in code_counts:
                    code_counts[status_code] += 1

            if line_count % 10 == 0:
                print_stats(total_size, code_counts)
        if line_count == 0 or line_count % 10 != 0:
            print_stats(total_size, code_counts)
    except KeyboardInterrupt:
        print_stats(total_size, code_counts)


if __name__ == "__main__":
    main()
