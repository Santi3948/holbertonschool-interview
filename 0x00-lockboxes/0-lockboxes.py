#!/usr/bin/python3
'''Write a method that determines if all the boxes can be opened.'''


def canUnlockAll(boxes):
    '''the function'''
    new_dict = {}
    new_list = [0]
    new_dict[0] = True
    for i in range(1, len(boxes)):
        new_dict[i] = False
    count = 1
    while new_list:
        keys = boxes[new_list.pop()]
        for j in keys:
            if not new_dict[j]:
                new_list.append(j)
                new_dict[j] = True
                count += 1
    return len(boxes) == count
