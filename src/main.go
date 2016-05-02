package main

import (
	"bufio"
	"fmt"
	"os"
)

var stdin *bufio.Reader
var stdout *bufio.Writer

func init() {
	stdin = bufio.NewReader(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func isPrime(n int) bool {

	if n == 2 || n == 3 {
		return true
	} else if n == 1 || n%2 == 0 || n%3 == 0 {
		return false
	}

	for i := 6; (i-1)*(i-1) <= n; i += 6 {
		if n%(i-1) == 0 || n%(i+1) == 0 {
			return false
		}
	}

	return true
}

func main() {
	n, max := 0, 0
	fmt.Fscanf(stdin, "%d\n", &n)

	one, odd, even := make([]int, 0), make([]int, 0), make([]int, 0)
	for i := 0; i < n; i++ {
		number := 0
		fmt.Fscanf(stdin, "%d", &number)
		switch {
		case number == 1:
			one = append(one, 1)
		case number%2 == 0:
			even = append(even, number)
		case number%2 == 1:
			odd = append(odd, number)
		}
	}
	fmt.Fscanf(stdin, "\n", nil)

	/* Choose all 1 and select 1 even number */
	if len(one) > 0 && len(even) > 0 {
		for _, value := range even {
			if isPrime(value+1) == true {
				max = len(one) + 1
				fmt.Fprintf(stdout, "%d\n", max)
				for i := 0; i < len(one); i++ {
					fmt.Fprintf(stdout, "1 ")
				}
				fmt.Fprintf(stdout, "%d\n", value)
				stdout.Flush()
				return
			}
		}
	}
	
	if len(one) >= 2 {
		fmt.Fprintf(stdout, "%d\n", len(one))
		for i := 0; i < len(one); i++ {
			fmt.Fprintf(stdout, "1 ")
		}
		fmt.Fprintf(stdout, "\n")
		stdout.Flush()
		return
	}	

	if len(odd) > 0 && len(even) > 0 {
		for i := 0; i < len(odd); i++ {
			for j := 0; j < len(even); j++ {
				if isPrime(odd[i]+even[j]) == true {
					fmt.Fprintf(stdout, "2\n%d %d\n", odd[i], even[j])
					stdout.Flush()
					return
				}
			}
		}
	}
	
	if len(one) > 0 {
		fmt.Fprintf(stdout, "1\n1\n")
		stdout.Flush()
		return
	}
		
	if len(odd) > 0 {
		fmt.Fprintf(stdout, "1\n%d\n", odd[0])
		stdout.Flush()
		return
	}
	
	if len(even) > 0 {
		fmt.Fprintf(stdout, "1\n%d\n", even[0])
		stdout.Flush()
		return
	}	

	fmt.Fprintf(stdout, "0\n")

	stdout.Flush()
}
