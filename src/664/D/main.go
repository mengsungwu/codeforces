
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

type Edge struct {
    from, to int
    color rune
}

var edges [][]Edge
var visit []int
var list [][]int

func dfs(node int, flip int, color rune) bool {
    
    //fmt.Fprintf(stdout, "%v %v %v %v\n", node, visit[node], flip, color)
    if visit[node] != 0 {
        return visit[node] == flip
    }
    
    visit[node] = flip
    list[flip] = append(list[flip], node)

    for _, edge := range edges[node] {
        if (flip == 2 && edge.color == color) || (flip == 1 && edge.color != color) {
            if dfs(edge.to, 2, color) == false {
                return false
            }
        } else {
            if dfs(edge.to, 1, color) == false {
                return false
            }
        }
    }
    return true
}


func try(color rune) (res []int, ok bool) {
    visit   = make([]int, len(edges))
    list    = make([][]int, 3)

    
    for i := 0; i < len(visit); i++ {
        if visit[i] != 0 {
            continue
        }
        
        list[1] = make([]int, 0)
        list[2] = make([]int, 0)
                
        if dfs(i, 1, color) == false {
            return res, false
        }
        
        if len(list[1]) <= len(list[2]) {
            for _, n := range list[1] {
                res = append(res, n)
            }
        } else {
            for _, n := range list[2] {
                res = append(res, n)
            }
        }
    }
    
    return res, true
}

func main() {

    n, m := 0, 0
    fmt.Fscanf(stdin, "%d%d\n", &n, &m)
    
    edges = make([][]Edge, n)
    
    for i := 0; i < m; i++ {
        var from, to int
        var color rune
        fmt.Fscanf(stdin, "%d%d %c\n", &from, &to, &color)
        from--
        to--
        
        edges[from] = append(edges[from], Edge{from, to, color})
        edges[to] = append(edges[to], Edge{to, from, color})
    }
    
    v1, ok1 := try('R')
    v2, ok2 := try('B')

    if ok1 == false && ok2 == false {
        fmt.Fprintf(stdout, "-1\n")
    } else {
        var v []int
        if ok1 == true {
            v = v1
        } else {
            v = v2
        }
        
        if ok2 == true && len(v) > len(v2) {
            v = v2
        }
        fmt.Fprintf(stdout, "%v\n", len(v))
        for _, vv := range v {
            fmt.Fprintf(stdout, "%v ", vv + 1)
        }
        fmt.Fprintf(stdout, "\n")
    }
    
    
    
    stdout.Flush()
}