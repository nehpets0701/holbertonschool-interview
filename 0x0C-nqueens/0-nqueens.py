#!/usr/bin/python3
""" N Queens """
import sys


def nQueens(row, N, queens, cols, diags, revDiags):
    """N Queens"""
    if row == N:
        if len(queens) == N:
            print(queens)
        return

    possibleMoves = []
    for col in range(N):
        if col in cols:
            continue
        if row - col in diags or N - col - row in revDiags:
            continue
        if [row, col] not in queens:
            possibleMoves.append(col)

    for col in possibleMoves:
        nQueens(
            row + 1,
            N,
            queens + [[row, col]],
            cols + [col],
            diags + [row - col],
            revDiags + [N - col - row]
        )

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

nQueens(0, N, [], [], [], [])
