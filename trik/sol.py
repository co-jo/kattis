import sys

line = raw_input()
cups = [1, 0, 0]

for char in line:
    if char == 'C':
        cups[0], cups[2] = cups[2], cups[0]
    elif char == 'B':
        cups[1], cups[2] = cups[2], cups[1]
    elif char == 'A':
        cups[0], cups[1] = cups[1], cups[0]

for index, val in enumerate(cups):
    if val == 1:
        print str(index + 1)
