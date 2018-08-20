package main
import "fmt"
import "bufio"
import (
	"os"
	"strconv"
)
func main() {
	//Enter your code here. Read input from STDIN. Print output to STDOUT
	var _ = strconv.Itoa
	scanner := bufio.NewScanner(os.Stdin)
	var s string
	scanner.Scan()
	s = scanner.Text()
	fmt.Printf("Hello, World.\n%s\n",s)
}