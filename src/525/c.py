

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = []
    area = 0
    a.sort()

    for i in reversed(range(len(a))):
        if i > 0 and (a[i] == a[i - 1] or a[i]-1 == a[i - 1]):
            b.append(a[i-1])
            a[i-1] = -1


    for i in range(int(len(b) / 2)):
        area += b[2*i] * b[2*i + 1]

    print(area)

if __name__ == '__main__':
    main()