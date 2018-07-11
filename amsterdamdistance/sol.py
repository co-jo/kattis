import math

segments, rings, radius = input().split()

segments = int(segments)
rings = int(rings)
radius = float(radius)

asg, arg, bsg, brg = [int(ele) for ele in input().split()]

# Calculate from outward in.
if arg < brg:
    arg, asg = brg, bsg

inout = 0
inacross = math.inf
around = math.inf

runit = radius/rings

# Cut in and go across
if arg != brg:
    inward = abs(arg - brg) * runit
    # Proportion of circle cover * (Circumfrence)
    across = abs(asg - bsg)/segments * math.pi * (radius/rings * brg)
    inacross = (inward + across)

# Cut in to origin, cut out to b.
inout = (arg * runit) + brg * runit

# If on same ring, go across
if arg == brg:
    around = abs(bsg - asg)/segments * math.pi * (brg/rings * radius)

print (min(inout, inacross, around))
