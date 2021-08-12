#!/usr/bin/python3
"""minimum operations"""


def minOperations(n):
    """minimum operations"""
    if n <= 1:
        return 0

    for x in range(int(n / 2), 0, -1):
        if n % x == 0:
            return int(n / x) + minOperations(x)
