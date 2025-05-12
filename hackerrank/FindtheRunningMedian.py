#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'runningMedian' function below.
#
# The function is expected to return a DOUBLE_ARRAY.
# The function accepts INTEGER_ARRAY a as parameter.
#

import heapq

def runningMedian(a):
    maxh = []
    minh = []
    ans = []

    for aa in a:
        if len(maxh) == 0 or aa <= -maxh[0]:
            heapq.heappush(maxh, -aa)
        else:
            heapq.heappush(minh, aa)

        if len(maxh) > len(minh) + 1:
            heapq.heappush(minh, -heapq.heappop(maxh))
        elif len(minh) > len(maxh):
            heapq.heappush(maxh, -heapq.heappop(minh))

        if len(maxh) > len(minh):
            m = -maxh[0]
        else:
            m = (-maxh[0] + minh[0]) / 2
        ans.append(format(m, ".1f"))

    return ans
# 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input().strip())

    a = []

    for _ in range(a_count):
        a_item = int(input().strip())
        a.append(a_item)

    result = runningMedian(a)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
