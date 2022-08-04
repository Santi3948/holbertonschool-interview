#!/usr/bin/python3
'''Write a method that determines if all the boxes can be opened.'''


def canUnlockAll(boxes):
    '''the function'''
    if len(boxes) <= 1:
        return True
    pend_lis = [0]
    open_lis = set(pend_lis)
    while pend_lis:
        pend = pend_lis.pop()
        for key in pend:
            if key < len(boxes) and key not in open_lis:
                pend_lis.append(key)
                open_lis.add(key)
    return len(open_lis) == len(boxes)
