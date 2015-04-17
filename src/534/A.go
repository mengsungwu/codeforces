package main

import "fmt"

func main() {
	n := 0
	fmt.Scanf("%d\n", &n)

	switch n {
	case 1:
		fmt.Println("1\n1")
	case 2:
		fmt.Println("1\n1")
	case 3:
		fmt.Println("2\n1 3")
	default:
		fmt.Println(n)
		for i := 2; i <= n; i += 2 {
			fmt.Printf("%d ", i)
		}
		for i := 1; i <= n; i += 2 {
			fmt.Printf("%d ", i)
		}		
		fmt.Println("")
	}
}