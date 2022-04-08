#!/usr/bin/python3
"""prime game"""


def isWinner(x, nums):
    """prime game"""
    winner = 0
    for round in range(x):
        prime = 0
        for n in range(1, nums[round] + 1):
            if n in [1, 2, 3] or n % 6 == 1 or n % 6 == 5:
                prime += 1
        winner += 1 if prime % 2 == 1 else -1
    if winner == 0:
        return None
    elif winner > 0:
        return "Ben"
    else:
        return "Maria"
