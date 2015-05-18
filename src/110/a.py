def islucky(n):
    for i, v in enumerate(str(n)):
        if v not in ('4', '7'):
            return False
    return True

s = input()
if islucky(sum([1 for x in s if x in ('4', '7')])):
    print('YES')
else:
    print('NO')