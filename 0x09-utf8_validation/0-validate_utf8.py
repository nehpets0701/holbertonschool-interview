#!/usr/bin/python3
"""utf validation"""


def validUTF8(data):
    """utf validation"""
    bits = [number & 255 for number in data]

    try:
        byte = bytes(bits)
        byte.decode()
    except:
        return False
    return True
