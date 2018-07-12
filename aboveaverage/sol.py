import sys;
input()

for line in sys.stdin:
    line = [int(ele) for ele in line.split()]
    avg = sum(line[1:])/len(line[1:])
    above = [ele for ele in line[1:] if ele > avg]
    print ('%.3f' % float(len(above)/len(line[1:]) * 100) + '%')
