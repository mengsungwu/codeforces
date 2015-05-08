def score(p, t):
    return max(int(3*p/10), int(p - t*p/250))

def main():
    a, b, c, d = [int(x) for x in input().split()]
    misha = score(a, c)
    vasya = score(b, d)

    if misha > vasya:
        print('Misha')
    elif misha < vasya:
        print('Vasya')
    else:
        print('Tie')

if __name__ == '__main__':
    main()