#!/usr/bin/python3
"""lockboxes"""


def canUnlockAll(boxes):
    """lockboxes"""
    if len(boxes) == 0:
        return False
    if boxes is None:
        return False

    return False not in unlock(0, boxes, [False for i in range(0, len(boxes))])


def unlock(box, boxes, opened):
    """lockboxes"""
    if opened[box] is False:
        opened[box] = True
        for key in boxes[box]:
            if key < len(boxes):
                unlock(key, boxes, opened)
    return opened
