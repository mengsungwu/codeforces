package main

import "fmt"
import "strings"

func main() {
	for {
		s, t := "", ""
		n, _ := fmt.Scanf("%s\n", &s)

		if n == 0 {
			break
		}

		for i := 0; i < len(s); i++ {
			switch s[i] {
				case 'a', 'e', 'i', 'o', 'u', 'y',
					 'A', 'E', 'I', 'O', 'U', 'Y':
				default:
					t = t + "." + string(s[i])
			}
		}

		t = strings.ToLower(t)
		fmt.Println(t)
	}
}