package main
import (
"fmt"
"math"
)

func potolok(a int) int{
    return int(math.Ceil(float64(a)/26.0))-1
}

func main() {
    var a int
    arr := make([]int,0)
    fmt.Scan(&a)
    var qn int = potolok(a)
    var qn_ int = potolok(qn)
    var str string = ""
    
    for i:=0;true;i++{
        if i == 0{
            arr = append(arr,a-26*qn)
        }else if (qn) == 0{
            break
        }else{
            arr = append(arr,qn-26*qn_)
            qn = qn_
            qn_ = potolok(qn)
        }
    }

    for i:=len(arr)-1;i>=0;i--{
        str += string(arr[i]+64)
    }
    fmt.Println(str)
}