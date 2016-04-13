
package main

import "fmt"


func main() {
    n := 0
    
    fmt.Scanf("%d\n", &n)
    
    a := make([]uint, n)
    b := make([]uint, n)
   
    for i := 0; i < n; i++ {
       _, err := fmt.Scanf("%d", &a[i])
       if err != nil {
           fmt.Scanf("%d", &a[i])
       }
    }
    
    for i := 0; i < n; i++ {
       _, err := fmt.Scanf("%d", &b[i])
       if err != nil {
           fmt.Scanf("%d", &b[i])
       }
    }
    
    for i := 1; i < n; i++ {
        a[0] |= a[i]
        b[0] |= b[i]
    }
    
    
    fmt.Println(a[0] + b[0])
    
}