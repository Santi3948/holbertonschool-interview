#!/usr/bin/python3
""" 0. Minimum Operations"""


def minOperations(n):
    """minimum operations"""
    if n < 2 or type(n) is not int:
        return 0
    descompose = []
    val = n
    i = 1
    while val != 1:
        i += 1
        if val % i == 0:
            while (val % i == 0 and val != 1):
                val = val / i
                descompose.append(i)
    return sum(descompose)
