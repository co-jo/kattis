line = input()

a = line.split()[-2]
b = line.split()[-1]

c = ""
d = ""

for i in range(len(a)-1, -1, -1):
    c += a[i]
    d += b[i]

print(max(c,d))
