if __name__ == '__main__':
	word = input()
	flag = 0
	for i in range(1, len(word)):
		if word[i].islower():
			flag = 1 			
			break
	if flag == 1:
		print(word)
	else:
		print(word.swapcase())
