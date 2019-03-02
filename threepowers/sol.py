import sys
from math import log

for n in sys.stdin:
    if (not int(n)): break
    n = int(n) - 1

    arr = []
    while (n > 0):
        p = int(log(n,2))
        arr.append(pow(3, p))
        n = n - pow(2, p)

    arr.sort()
    subset = ''.join(str(e) + ", " for e in arr)

    if (not len(arr)):
        print("{ }")
    else:
        print("{ " + subset[:-2] + " }")

