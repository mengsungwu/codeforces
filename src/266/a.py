
if __name__ == '__main__':
    n = int(input())
    string = input()
    total = 0
    for i in range(len(string)):
        if i > 0 and string[i] == string[i - 1]:
            total += 1
    print(total)