
package main

import (
    "os"
    "bufio"
    "fmt"
)

var stdin *bufio.Reader

func init() {
    stdin = bufio.NewReader(os.Stdin)
}

func main() {
    
    n, m := 0, 0

    fmt.Fscanf(stdin, "%d%d\n", &n, &m)
    
    for i := 0; i < n; i++ {
        if 2*n + 2*i + 1 <= m {
            fmt.Printf("%d ", 2*n + 2*i + 1)
        }
        
        if 2*i + 1 <= m {
            fmt.Printf("%d ", 2*i + 1)
        }

        if 2*n + 2*i + 2 <= m {
            fmt.Printf("%d ", 2*n + 2*i + 2)
        }
        
        if 2*i + 2 <= m {
            fmt.Printf("%d ", 2*i + 2)
        }                        
    }
}