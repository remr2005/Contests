package main
import (
    "bufio"
    "fmt"
    "log"
    "os"
    "strings"
    "sort"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    line, err := reader.ReadString('\n')
    if err != nil {
        log.Fatal(err)
    }
   var arr []string = strings.Fields(line)
   var n int
   for i:=0; i < len(arr);  i++{
       if arr[i] == "end"{
           n = i
           break
       }
   }
   arr = arr[0:n]
   sort.Strings(arr)
   var res string = ""
   var f bool = true
   for i:=0; i < n-1;  i++{
       if (arr[i] == arr[i+1]) && (f == true){
           res += arr[i] + " "
           f = false
       }else if (arr[i] == arr[i+1]) && (f == false){
           continue
       }else{
           f = true
       }
   }
   fmt.Println(res)
}