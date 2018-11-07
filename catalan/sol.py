from math import factorial 
count = int(input())
list = []

def catalan(n):
    val = factorial(n)
    return factorial(2 * n)//(val * val * (n + 1))

for i in range(count):
    n = int(input())
    list.append(catalan(n))


for i in range(count):
    print (list[i])
