_, k = [int(x) for x in input().split()]
print(sorted([int(x) for x in input().split()], reverse=True)[k - 1])
