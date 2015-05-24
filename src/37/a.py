n = int(input())
kit = [int(x) for x in input().split()]
tower = {}
for v in kit:
    tower[v] = tower.get(v, 0) + 1;
print(max(tower.values()), len(tower))