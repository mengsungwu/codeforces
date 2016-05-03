
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

type Node struct {
	attacked bool
	neighbor []int
}

var nodes []Node
var point1, point2 int

func dfs(x, parent int) (int, int, bool) {
	
	maxlength, maxendpoint := 0, 0
	for _, v := range nodes[x].neighbor {
		if v == parent {
			continue
		}
		
		length, endpoint ,flag := dfs(v, x)
		
		if flag == true {
			nodes[x].attacked = true
			if length > maxlength || (length == maxlength && endpoint < maxendpoint) {
				maxlength = length
				maxendpoint = endpoint
			}
		}
	}
	
	if nodes[x].attacked {
		if maxlength == 0 {
			return maxlength + 1, x, true
		} else {
			return maxlength + 1, maxendpoint, true
		}		
	} else {
		return 0, 0, false
	}
}


func main() {
	n, m := 0, 0
	
	fmt.Fscan(stdin, &n)
	fmt.Fscan(stdin, &m)
	
	nodes = make([]Node, n)
	
	for i := 0; i < n - 1; i++ {
		u, v := 0, 0
		fmt.Fscan(stdin, &u)
		fmt.Fscan(stdin, &v)
		u--
		v--
		nodes[u].neighbor = append(nodes[u].neighbor, v)
		nodes[v].neighbor = append(nodes[v].neighbor, u)
	}
	
	for i := 0; i < m; i++ {
		c := 0
		fmt.Fscan(stdin, &c)
		nodes[c - 1].attacked = true
	}
	
	for i := 0; i < n; i++ {
		if nodes[i].attacked == true {
			_, point1, _ = dfs(i, -1)
			break
		}
	}
	
	diameter, point2, _ := dfs(point1, -1)
	res := 0
	for i := 0; i < n; i++ {
		if nodes[i].attacked == true {
			res += 2
		}
	}
	
	if point1 > point2 {
		point1 = point2
	}
	
	fmt.Fprintf(stdout, "%d\n%d\n", point1 + 1, res - 1 - diameter)
	
	
	stdout.Flush()
}
