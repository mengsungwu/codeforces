
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

func check(grid [][]int, row1, row2, col1, col2 int) int {
	count := 0
	for i := row1; i <= row2; i++ {
		for j := col1; j <= col2; j++ {
			count += grid[i][j]
		}
	}
	return count
}

func main() {

	r, c, n, k := 0, 0, 0, 0
	fmt.Fscanf(stdin, "%d%d%d%d\n", &r, &c, &n, &k)
	
	grid := make([][]int, r)
	for i := 0; i < r; i++ {
		grid[i] = make([]int, c)
	}
	
	for i := 0; i < n; i++ {
		x, y := 0, 0
		fmt.Fscanf(stdin, "%d%d\n", &x, &y)
		grid[x - 1][y - 1] = 1;
	}
	
	count := 0
	
	for r1 := 0; r1 < r; r1++ {
		for r2 := r1; r2 < r; r2++ {
			for c1 := 0; c1 < c; c1++ {
				for c2 := c1; c2 < c; c2++ {
					if check(grid, r1, r2, c1, c2) >= k {
						count++
					}
				} 
			}
		}
	}
	

	fmt.Fprintf(stdout, "%d\n", count)

    stdout.Flush()
}