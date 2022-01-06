#!/usr/bin/python3
"""rotates a 2D matrix"""


def rotate_2d_matrix(matrix):
    rotated = list(zip(*matrix[::-1]))
    for x in range(len(rotated)):
        for num in range(len(rotated[x])):
            matrix[x][num] = rotated[x][num]
