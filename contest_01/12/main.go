package main
import "fmt"

func main() {
    var i int;
    fmt.Scan(&i)
    var n int = 0;
    for i != 1{
        if i%2==0{
            i /=2
        }else{
            i = 3*i + 1
        }
        n+=1
    }
    fmt.Println(n)
}