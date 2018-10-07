import sys

cost = input()
lawns = input()

sum = 0.0
for i in range(int(lawns)):
    width, length = [float(word) for word in input().split()]
    sum = sum + (width * length)

print(format(sum * float(cost), '.7f'))
