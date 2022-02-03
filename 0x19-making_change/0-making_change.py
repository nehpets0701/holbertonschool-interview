#!/usr/bin/python3
"""making change"""


def makeChange(coins, total):
    """making change"""
    if total <= 0:
        return 0
    if total in coins:
        return 1

    amount = 0
    current = 0
    coins = reversed(sorted(coins))

    for coin in coins:
        while current + coin <= total:
            amount += 1
            current += coin
    if current != total:
        return -1
    return amount
