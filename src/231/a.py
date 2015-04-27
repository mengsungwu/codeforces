if __name__ == '__main__':
	n = int(input())
	total = 0
	for i in range(n):
		l = [int(x) for x in input().split()]
		if sum(l) > 1:
			total += 1
	print(total)
