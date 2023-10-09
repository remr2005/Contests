package main
import "fmt"

func three_hundret_backs(a int, arr [5]int) [5]int{
    if a == 0{
        return arr
    }else if (a / 5000)>0{
        arr[0] += 1
        return three_hundret_backs(a-5000,arr)
    }else if (a / 1000)>0{
        arr[1] += 1
        return three_hundret_backs(a-1000,arr)
    }else if (a / 500)>0{
        arr[2] += 1
        return three_hundret_backs(a-500,arr)
    }else if (a / 200)>0{
        arr[3] += 1
        return three_hundret_backs(a-200,arr)
    }else{
        arr[4] += 1
        return three_hundret_backs(a-100,arr)
    }
}

func main() {
    var a int
    fmt.Scan(&a)
    var arr [5]int = three_hundret_backs(a,[5]int{0,0,0,0,0})
    fmt.Println(arr[0],arr[1],arr[2],arr[3],arr[4])
}