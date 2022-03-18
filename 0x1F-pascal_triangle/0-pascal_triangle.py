#!/usr/bin/python3
"""function"""


def pascal_triangle(n):
    """function"""
    if n <= 0:
        return []

    row = [1]
    y = [0]
    triangle = [[1]]
    for x in range(n - 1):
        row = [left+right for left, right in zip(row + y, y + row)]
        triangle.append(row)
    return triangle
