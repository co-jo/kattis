n = int(input())

for i in range(n):
    line = input();
    arr = [0 if ele == "" else int(ele) for ele in line.split(",")]
    res = 0
    base = 1
    for val in arr[::-1]:
        res = res + (val * base)
        base = base * 60

    print(res)
