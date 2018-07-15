import random

file = open("4.in", "w")

houses = 10000
lines = 7000

sample = {}

for i in range(1, houses):
    possible = list(range(1, houses))
    possible.remove(i)
    sample[i] = possible

file.write(str(houses) + " ")
file.write(str(lines) + "\n")

for i in range(0, lines):
    start = random.randint(1, houses - 1)
    end = random.randint(0, len(sample[start]) - 1)

    end = sample[start][end];

    # Remove
    sample[start].remove(end)
    if len(sample[start]) == 0:
        quit()

    file.write(str(start) + " ")
    file.write(str(end) + "\n")


