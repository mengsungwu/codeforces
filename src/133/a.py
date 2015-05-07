
def main():
    string = input()
    for i in range(len(string)):
        if string[i] == 'H' or string[i] == 'Q' or string[i] == '9':
            print('YES')
            return
    print('NO')

if __name__ == '__main__':
    main()