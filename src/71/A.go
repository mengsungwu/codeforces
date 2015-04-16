package main

import "fmt"

func main() {
	n := 0
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		s := ""
		fmt.Scanf("%s\n", &s)
		if len(s) > 10 {
			fmt.Printf("%c%d%c\n", s[0], len(s) - 2, s[len(s) - 1])
		} else {
			fmt.Println(s)
		}
	}
}