num = int(raw_input())
vals = raw_input().split()
count = 0

for val in vals:
    if int(val) < 0:
        count = count + 1

print count
