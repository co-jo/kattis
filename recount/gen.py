import random

names = [
         "Penny Franklin",
         "Marti Graham",
         "Joseph Ivers",
         "Connie Froggatt",
         "Penny Franklin",
         "Bruce Stranger",
         "Barbara Skinner",
         "Steph Murry",
         "Lemom James",
         "Stephen Drift"
]

file = open("1.in", "w")
for i in range(0, 100000):
    file.write(names[random.randint(0,9)] + '\n')

file.write("***\n")

