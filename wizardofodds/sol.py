import sys

line = sys.stdin.readline().split()
number = int(line[0])
guesses = int(line[1])

if (2 ** guesses >= number):
    print 'Your wish is granted!'
else:
    print 'You will become a flying monkey!'

