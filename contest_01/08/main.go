package main
import (
    "fmt"
    "sort"
    )
func main() {
    var a int 
    var b int
    var c int
    fmt.Scan(&a,&b,&c)
    nums := []int{a,b,c}
    sort.Ints(nums)
    fmt.Println(nums[2])
}