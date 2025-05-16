import math
import os
import random
import re
import sys

def map(M):
    m = [M] * (M+1)
    m[0:3] = [0,1,2]
    for i in range(2, M):
        m[i+1] = min(m[i+1], 1 + m[i])
        for j in range(2, i+1):
            if i * j > M: break
            m[i * j] = min(m[i * j], 1 + m[i])
    return m

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    m = map(10**6)

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        result = m[n]

        fptr.write(str(result) + '\n')

    fptr.close()
