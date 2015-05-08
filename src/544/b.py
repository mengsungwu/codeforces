def main():
    n, k = [int(x) for x in input().split()]
    if k > int( (n*n + 1) / 2 ):
        print('NO')
        return
    print('YES')
    for i in range(n):
        for j in range(n):
            if k > 0 and (i + j) % 2 == 0:
                print('L',end='')
                k -= 1
            else:
                print('S',end='')
        print('')


if __name__ == '__main__':
    main()