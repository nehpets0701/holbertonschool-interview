#!/usr/bin/python3
"""function"""


def island_perimeter(grid):
    """perimeter function"""
    perimeter = 0
    for x in range(0, len(grid)):
        for y in range(0, len(grid[x])):
            if grid[x][y] == 1:
                perimeter += 4
                if y != len(grid[x]) - 1:
                    if grid[x][y + 1] == 1:
                        perimeter -= 1
                if y != 0:
                    if grid[x][y - 1] == 1:
                        perimeter -= 1
                if x != len(grid) - 1:
                    if grid[x + 1][y] == 1:
                        perimeter -= 1
                if x != 0:
                    if grid[x - 1][y] == 1:
                        perimeter -= 1
    return perimeter
