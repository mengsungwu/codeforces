package main

import "fmt"

func main() {
	for {
		var w int64
		nRead, _ := fmt.Scanf("%d\n", &w)
		if nRead != 1 {
			break
		}
		if w == 2 || w % 2 == 1 {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
		}
	}
}