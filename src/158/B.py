if __name__ == '__main__':
	n = int(input())
	s = input().split()
	s = [int(x) for x in s]

	count = [0, 0, 0, 0, 0]
	car = 0
	for x in s:
		count[x] += 1

	car += count[4]

	car += count[3]
	count[1] = max(0, count[1] - count[3])

	car += int(count[2] / 2)
	if count[2] % 2 != 0:
		car += 1
		count[1] = max(0, count[1] - 2)

	car += int(count[1] / 4)

	if count[1] % 4 != 0:
		car += 1

	print(car)
