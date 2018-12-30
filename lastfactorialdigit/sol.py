from math import factorial

cases = int(input())

for i in range(cases):
    n = int(input())
    print(str(factorial(n))[-1])
