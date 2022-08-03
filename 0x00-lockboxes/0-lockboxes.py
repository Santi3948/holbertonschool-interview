#!/usr/bin/python3
'''Write a method that determines if all the boxes can be opened.'''


def canUnlockAll(boxes):
    '''the function'''
    new_dict = {}
    new_list = [0]
    new_dict[0] = True
    for i in range(1, len(boxes)):
        new_dict[i] = False
    [new_list.append(j) for j in boxes[0]]
    for item in new_list:
        if new_dict[item] is False:
            new_dict[item] = True
            [new_list.append(j) for j in boxes[item] if j not in new_list]
    aux = list(set(list(new_dict.values())))
    print(aux)
    return len(list(set(list(new_dict.values())))) == 1 and aux[0] is True
