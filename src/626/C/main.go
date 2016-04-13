
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

func main() {

	n, m := 0, 0
	
	fmt.Fscanf(stdin, "%d%d", &n, &m)
	
	x := 2 * n
	
	if 3 * m > x {
		x = 3 * m
	}
	
	for {
		if x / 2 + x / 3 - x / 6 >= n + m {
			break
		}
		x++
	}
	
	fmt.Fprintf(stdout, "%d\n", x)

    stdout.Flush()
}