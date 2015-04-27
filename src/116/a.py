if __name__ == '__main__':
	n = int(input())
	passengers = 0
	capacity = 0
	for i in range(n):
		a, b = input().split()
		passengers += int(b) - int(a)
		capacity = max(capacity, passengers) 
	print(capacity)
