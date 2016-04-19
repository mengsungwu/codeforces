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

type Point struct {
	x, y int
}

type Vector struct {
	dx, dy int
}

func main() {
	n, count := 0, 0
	fmt.Fscanf(stdin, "%d\n", &n)

	points := make([]Point, n)
	vectors := make(map[Vector]int)

	for i := 0; i < n; i++ {
		fmt.Fscanf(stdin, "%d%d\n", &points[i].x, &points[i].y)
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			var vector Vector
			 
			if points[i].x > points[j].x || (points[i].x == points[j].x && points[i].y >= points[j].y) {
				vector = Vector{points[i].x - points[j].x, points[i].y - points[j].y}
			} else {
				vector = Vector{points[j].x - points[i].x, points[j].y - points[i].y}
			}
			count += vectors[vector]
			vectors[vector]++
		}
	}
	fmt.Fprintf(stdout, "%d\n", count / 2)

	stdout.Flush()
}
