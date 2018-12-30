from math import factorial

num = int(input())

def catalan(i):
    return factorial(2*i)//(factorial(i)*factorial(i)*(i+1))

print(catalan(num + 1))
