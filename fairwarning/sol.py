import math

cases = int(input())

def gcd(a, b):
    if (not b):
        return a
    return gcd(b, a % b)

for i in range(cases):
    line = [int(time) for time in input().split()[1:]]
    line.sort()

    differences = []
    for j in range(0, len(line)):
        differences.append(line[j] - line[j - 1])

    factor = differences[0]
    for time in differences[1:]:
        factor = gcd(factor, time)

    time = factor - ((line[-1] + factor) % factor)

    # The extra mod simply handles when the last time given is already
    # divisible by factor
    print ("Case #" + str(i + 1) + ":", time % factor)
