#!/usr/bin/python3
'''Write a method that determines if all the boxes can be opened.'''


def canUnlockAll(boxes):
    '''the function'''
    aux = []
    bul = True
    [aux.append(item) for item in boxes[0]]
    print(aux)
    for i in range(1,len(aux)):
        if i in aux:
            [aux.append(item) for item in boxes[i]]
        
    #for item in boxes:
    return True
        