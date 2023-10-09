package main

import (
    "strconv"
    "fmt"
)


func main() {
    
    var first int
    var second int
    
    var first_nums [10]int8 = [10]int8{0,0,0,0,0,0,0,0,0,0}
    var second_nums [10]int8 = [10]int8{0,0,0,0,0,0,0,0,0,0}
    
    fmt.Scan(&first,&second)
    
    var local_len int = len(strconv.Itoa(first))
    
    if local_len != len(strconv.Itoa(second)) {
        fmt.Println("NO")
    }else{
        for i:=0; i < local_len; i++{
            first_nums[first%10] += 1
            second_nums[second%10] += 1
            first /= 10
            second /= 10
        }
        if first_nums == second_nums{
            fmt.Println("YES")
        }else{
            fmt.Println("NO")
        }
    }
    
    
}
