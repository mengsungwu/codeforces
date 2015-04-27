if __name__ == '__main__':
	n = int(input())
	x = 0
	for i in range(n):
		statement = input()
		if statement[1] == '+':
			x += 1
		elif statement[1] == '-':
			x -= 1
		else:
			panic('')
	print(x)
