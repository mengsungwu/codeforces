package main

import "fmt"
import "sort"

var luckyNumberDigit [11]float64
var luckyNumber []float64

func generate(depth int) {
	if depth <= 10 {
		lucky := float64(0)
		for i := depth; i >= 0; i-- {
			lucky = lucky * 10 + float64(luckyNumberDigit[i])
		}

		if lucky != 0 {
			luckyNumber = append(luckyNumber, lucky)
		}

		if depth < 10 {
			luckyNumberDigit[depth] = 4
			generate(depth + 1)
			luckyNumberDigit[depth] = 7
			generate(depth + 1)
			luckyNumberDigit[depth] = 0
		}
	}
}

func main () {
	luckyNumber = make([]float64, 0, 1000000)
	generate(0)

	sort.Float64s(luckyNumber)

	n := 0
	fmt.Scanf("%d\n", &n)
	fmt.Println(sort.SearchFloat64s(luckyNumber, float64(n)) + 1)
}
