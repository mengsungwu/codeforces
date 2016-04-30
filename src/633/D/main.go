package main

import (
	"bufio"
	"fmt"
	"os"
    "sort"
)

var stdin *bufio.Reader
var stdout *bufio.Writer

func init() {
	stdin = bufio.NewReader(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func lengthOfFib(frequency map[int]int, f1 int, f2 int) int {

	if f1 == 0 && f2 == 0 {
		return frequency[0] + 2
	}

	length := 2

	if frequency[f1+f2] > 0 {
		frequency[f1+f2]--
		length = 1 + lengthOfFib(frequency, f2, f1+f2)
		frequency[f1+f2]++
	}

	return length
}

func main() {

	var (
		n         int
		max       int
		numbers   []int
		frequency map[int]int
	)

	fmt.Fscanf(stdin, "%d\n", &n)

	numbers = make([]int, n)
	frequency = make(map[int]int)

	for i := 0; i < n; i++ {
		fmt.Fscanf(stdin, "%d", &numbers[i])
		frequency[numbers[i]]++
	}
    
    sort.Ints(numbers)

	max = 0
	for i := 0; i < n; i++ {
        if i > 0 && numbers[i - 1] == numbers[i] {
            continue
        }
		frequency[numbers[i]]--
		for j := 0; j < n; j++ {

			if i == j {
				continue
			}
            if j > 0 && j - 1 != i && numbers[j - 1] == numbers[j] {
                continue
            }            

			frequency[numbers[j]]--
			length := lengthOfFib(frequency, numbers[i], numbers[j])

			if length > max {
				max = length
			}
            frequency[numbers[j]]++
		}
        frequency[numbers[i]]++
	}

	fmt.Fprintf(stdout, "%d\n", max)

	stdout.Flush()
}