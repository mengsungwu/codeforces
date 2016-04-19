def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

if __name__ == '__main__':
    x, y = [int(x) for x in input().split()]
    if y > x:
        print('1')
    else:
        print(x)
    
