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
	n, k := 0, 0
	fmt.Fscanf(stdin, "%d%d\n", &n, &k)

	array := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(stdin, "%d", &array[i])
	}

	begin, end := 0, 0
	for count := 0; end < n && count <= k; end++ {
		if array[end] == 0 {
			if count < k {
				count++
			} else {
				break
			}
		}
	}

	max := end - begin
	maxBegin := begin
	maxEnd := end

	for end < n {
        
        if array[begin] == 0 {
		    begin++
            end++
        } else {
            begin++
        }
        
		for end < n && array[end] == 1 {
			end++
		}

		if end-begin > max {
			max = end - begin
			maxBegin = begin
			maxEnd = end
		}
	}
    
    fmt.Println(max)    
    for i := 0; i < n; i++ {
        if i >= maxBegin && i < maxEnd {
            fmt.Fprint(stdout, "1 ")
        } else {
            fmt.Fprintf(stdout, "%d ", array[i])
        }  
    }
    stdout.Flush()
}
