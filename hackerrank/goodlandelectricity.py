#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pylons' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#

def pylons(k, arr):
    n = len(arr)
    plants = 0
    i = 0
    while i < n:
        plant_pos = -1
        for j in range(min(n - 1, i + k - 1), max(-1, i - k), -1):
            if arr[j] == 1:
                plant_pos = j
                break
                
        if plant_pos == -1:
            return -1  
        plants += 1
        i = plant_pos + k
    return plants

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = pylons(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
