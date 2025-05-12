\
import math
import os
import random
import re
import sys
def nonDivisibleSubset(k, s):
    rem=[0]*k
    for i in range(len(s)):
        rem[s[i]%k]+=1
    count=min(rem[0],1)
    for j in range(1,(k//2)+1):
        if j!=k-j:
            count+=max(rem[j],rem[k-j])
        else:
            count+=min(rem[j],1)
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    s = list(map(int, input().rstrip().split()))

    result = nonDivisibleSubset(k, s)

    fptr.write(str(result) + '\n')

    fptr.close()
