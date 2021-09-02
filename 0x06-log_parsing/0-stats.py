#!/usr/bin/python3
import sys


def printStats(stats, size):
    stats = [200, 301, 400, 401, 403, 404, 405, 500]
    print("File size: {}".format(size))
    for i in range(len(stats)):
        if stats[stats[i]] > 0:
            print("{}: {}".format(stats[i], stats[stats[i]]))

count = 0
size = 0
dicti = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
try:
    for line in sys.stdin:
        try:
            count += 1
            linesplit = line.split()
            size += int(linesplit[-1])
            status = int(linesplit[-2])
            dicti[status] += 1
            if count == 10:
                count = 0
                printStats(dicti, size)
        except Exception:
            continue
except Exception:
    pass
finally:
    printStats(dicti, size)
