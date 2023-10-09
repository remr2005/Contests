package main

import (
	"fmt"
	//"strconv"
)

func main() {
    var n int
    var str string = ""
    fmt.Scan(&n); 
    arr := make([]float64, n)

    for i := 0;i<n;i++{

        if _, err := fmt.Scan(&arr[i]); err != nil {
            panic(err)
        }
    }
    
    arr_ := make([]float64,n)
    arr_[0] = arr[0]
    arr_[n-1] = arr[n-1]
    for i:=1;i<n-1;i++{
        arr_[i] = (arr[i-1]+arr[i]+arr[i+1])/3.0
    }
    
    for i:=0;i<n;i++{
        str = str + fmt.Sprintf("%v", arr_[i]) + " "
    }
    fmt.Println(str)
}