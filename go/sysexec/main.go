package main
import (
  "os"
  "log"
  "fmt"
  "syscall"
)


func main(){
  fmt.Println("Exec: ", os.Args[1:])
  err := syscall.Exec(os.Args[1], os.Args[1:], []string{})
  fmt.Println("Error: ", err)
  log.Panicln("exec failed:", err)
}
