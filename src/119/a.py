def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

a, b, n = [int(x) for x in input().split()]
player = 0
while n != 0:
    if player == 0:
        n -= gcd(n, a)
        player = 1
    else:
        n -= gcd(n, b)
        player = 0

print(1 if player == 0 else 0)
