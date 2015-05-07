
def main():
    s1 = input().upper()
    s2 = input().upper()

    if s1 < s2:
        print('-1')
    elif s1 > s2:
        print('1')
    else:
        print('0')


if __name__ == '__main__':
    main()
