import sys

num = input()

for line in sys.stdin:
    num = int(line[:-1])
    if (num % 2):
        print str(num) + ' is odd'
    else:
        print str(num) + ' is even'
