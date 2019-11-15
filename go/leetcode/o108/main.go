/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func defangIPaddr(address string) string {
	var res = ""
	for _, c := range address {
		if c == '.'{
			res += "[.]"
		}else {
			res += string(c)
		}
	}
	return res
}

func main() {
	fmt.Println(defangIPaddr("192.168.1.1"))
}