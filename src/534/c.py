if __name__ == '__main__':
	n, a = [int(x) for x in input().split()]
	d = [int(x) for x in input().split()]

	total = sum(d)
	for i in range(n):
		count = 0
		count += max(0, d[i] - (a - (n - 1)))
		count += max(0, a - total + d[i] - 1)

		print(count, end=' ')
