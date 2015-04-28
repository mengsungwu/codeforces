if __name__ == '__main__':
	line = input()
	player = 0
	for i in range(len(line)):
		if i > 0 and line[i] == line[i-1]:
			player += 1
			if player >= 6:
				print('YES')
				break
		else:
			player = 0
	else:
		print('NO')

