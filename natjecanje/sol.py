line = input()
damaged = input().split()
reserves = input().split()
rmap = {num: int(num) for num in reserves}

def pluck(i, j):
    damaged[i] = -1
    reserves[j] = -1

for i, team in enumerate(damaged):
    # Give themselves priority.
    if team in rmap:
        del rmap[team]
        pluck(i, reserves.index(team))

for i in range(len(damaged)):
    # Other teams
    team = damaged[i]
    for j in range(len(reserves)):
        before = reserves[j]
        if abs(int(before) - int(team)) == 1:
            pluck(i, j)
            break

print (len(damaged) - damaged.count(-1))
