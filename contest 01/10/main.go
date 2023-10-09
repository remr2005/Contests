package main
import "fmt"
func Ja_oder_nein(a string) int{
    if a == "Да"{
        return 1
    }else{
        return 0
    }
}

func main() {
    var a_ string
    var b_ string
    var c_ string
    fmt.Scan(&a_,&b_,&c_)
    var a int = Ja_oder_nein(a_)
    var b int = Ja_oder_nein(b_)
    var c int = Ja_oder_nein(c_)
    if a == 0 && b == 0 && c == 0{
        fmt.Println("Кот")
    }else if a == 0 && b == 0 && c ==1{
        fmt.Println("Жираф")
    }else if a == 0 && b == 1 && c ==0{
        fmt.Println("Курица")
    }else if a == 0 && b == 1 && c ==1{
        fmt.Println("Страус")
    }else if a == 1 && b == 0 && c ==0{
        fmt.Println("Дельфин")
    }else if a == 1 && b == 0 && c ==1{
        fmt.Println("Плезиозавры")
    }else if a == 1 && b == 1 && c ==0{
        fmt.Println("Пингвин")
    }else{
        fmt.Println("Утка")
    }
}