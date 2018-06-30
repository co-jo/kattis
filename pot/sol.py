import sys

data = sys.stdin.readlines()
sum = 0;

for line in data[1:]:
    string = line[:-1]
    sum += int(string[:-1]) ** int(string[-1:])

print(sum)
 
    
