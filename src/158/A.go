package main

import "fmt"

func main() {
	for {
		var n, k int
		nRead, _ := fmt.Scanf("%d%d\n", &n, &k)
		if nRead != 2 {
			break
		}

		score := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &score[i])
		}
		fmt.Scanf("\n")

		advanced := 0
		for i := 0; i < n; i++ {
			if score[i] > 0 && score[i] >= score[k-1] {
				advanced++
			}
		}

		fmt.Println(advanced)
	}
}