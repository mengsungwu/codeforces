n = int(input())
coins = [int(x) for x in input().split()]
coins.sort()
coins.reverse()
total = 0
for i, v in enumerate(coins):
    total += v
    if 2*total > sum(coins):
        print(i+1)
        break
