people = [ 'Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard' ]
n = int(input())
i = 1
while i*len(people) < n:
    n -= i*len(people)
    i *= 2
print(people[ int((n - 1) / i)] )

