package main

import "fmt"

func main() {
	for {
		var m, n, a int64
		nRead, _ := fmt.Scanf("%d%d%d\n", &m, &n, &a)
		if nRead != 3 {
			break
		}
		fmt.Println( ((m+a-1)/a) *((n+a-1)/a) )
	}
}