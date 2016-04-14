package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var stdin *bufio.Reader
var stdout *bufio.Writer

func init() {
	stdin = bufio.NewReader(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func main() {

	s, _ := stdin.ReadString('\n')
	s = strings.Trim(s, "\r\t\n")

	var frequency [256]int

	for _, c := range s {
		frequency[c]++
	}

	for i, j := int('a'), int('z'); i < j; {

		for i <= int('z') && frequency[i]%2 == 0 {
			i++
		}

		for j >= int('a') && frequency[j]%2 == 0 {
			j--
		}

		if i >= j {
			break
		}

		frequency[i]++
		frequency[j]--

	}

	for i := int('a'); i <= int('z'); i++ {
		for j := 0; j < frequency[i]/2; j++ {
			fmt.Fprintf(stdout, "%c", i)
		}
	}

	for i := int('a'); i <= int('z'); i++ {
		if frequency[i]%2 == 1 {
			fmt.Fprintf(stdout, "%c", i)
		}
	}

	for i := int('z'); i >= int('a'); i-- {
		for j := 0; j < frequency[i]/2; j++ {
			fmt.Fprintf(stdout, "%c", i)
		}
	}

	stdout.Flush()
}
