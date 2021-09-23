#!/usr/bin/python3


def validUTF8(data):
    bits = [number & 255 for number in data]

    try:
        byte = bytes(bits)
        byte.decode()
    except:
        return False
    return True
