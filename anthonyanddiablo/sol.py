from math import pi
a, b = input().split()

# Perimeter
available = float(b)
# Surface Area
required = float(a)

area = 0
# Largest area constructable
if (available != 0):
    radius = available/(2 * pi);
    area = pi * radius ** 2;

if (area >= required):
    print ("Diablo is happy!")
else:
    print ("Need more materials!")
