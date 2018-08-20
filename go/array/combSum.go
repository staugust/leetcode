package main

import (
	"sort"
	"fmt"
	"bufio"
	"os"
	"strconv"
)

func combinationSum(candidates []int, target int) [][]int {
	var res [][]int
	sort.Ints(candidates)
	
	//append(res, combinationSum(candidates[0:len(candidates) - 1], target - candidates[len(candidates - 1)]))
	return res
}

func flipAndInvertImage(A [][]int) [][]int {
	var res [][]int
	for _, row := range (A) {
		var r []int
		for i := len(row) - 1; i != -1; i-- {
			r = append(r, 1-row[i])
		}
		res = append(res, r)
	}
	return res
}

func isToeplitzMatrix(matrix [][]int) bool {
	m, n := len(matrix), len(matrix[0])
	
	for i := 0; i < n; i++ {
		tmp := matrix[0][i]
		for j := 1; j < n-i && j < m; j++ {
			if tmp != matrix[j][i+j] {
				return false
			}
		}
	}
	for i := 0; i != len(matrix); i++ {
		// (i,0) (i+1,0+1)
		tmp := matrix[i][0]
		for j := 1; j < m-i && j < n; j++ {
			if tmp != matrix[i+j][j] {
				return false
			}
		}
	}
	
	return true
}

func findDisappearedNumbers(nums []int) []int {
	sort.Ints(nums)
	i, j := 0, 1
	var res []int
	for i < len(nums) && j < len(nums)+1 {
		if nums[i] == j {
			i++
			j++
		} else if nums[i] < j {
			i++
		} else {
			res = append(res, j)
			j++
		}
	}
	return res
}

func isOneBitCharacter(bits []int) bool {
	var j = len(bits) - 2
	var total = 0
	for j > -1 {
		if bits[j] == 1 {
			total++
			j--
		} else {
			break
		}
	}
	return total%2 == 0
}

func maxProfit(prices []int) int {
	var mn = 0x8FFFFFFF
	var mx = -1
	var asc = false
	var total = 0
	for i := 0; i < len(prices); {
		val := prices[i]
		if asc {
			if val >= mx {
				mx = val
				i++
			} else {
				total += mx - mn
				asc = false
				mn = 0x8FFFFFFF
			}
		} else {
			if val <= mn {
				mn = val
				i++
			} else {
				asc = true
				mx = -1
			}
		}
	}
	if asc {
		total += prices[len(prices)-1] - mn
	}
	return total
}

func findShortestSubArray(nums []int) int {
	var mp = make(map[int]int)
	for _, val := range (nums) {
		mp[val] += 1
	}
	var mx = 0
	var keyLst []int
	for k, v := range (mp) {
		if v > mx {
			mx = v
			keyLst = append([]int{}, k)
		} else if v == mx {
			keyLst = append(keyLst, k)
		}
	}
	var res []int
	for _, key := range (keyLst) {
		var s, e = 0, 0
		for i := 0; i != len(nums); i++ {
			if nums[i] == key {
				s = i
				break
			}
		}
		
		for i := len(nums) - 1; i > -1; i-- {
			if nums[i] == key {
				e = i
				break
			}
		}
		res = append(res, e-s+1)
	}
	sort.Ints(res)
	return res[0]
}

func imageSmoother(M [][]int) [][]int {
	// deep copy 2-dimension array
	var m, n = len(M), len(M[0])
	var nw [][]int = make([][]int, m)
	for i := 0; i != m; i++ {
		nw[i] = make([]int, n)
	}
	for i := 0; i != m; i++ {
		for j := 0; j != n; j++ {
			var c = 1
			nw[i][j] = M[i][j]
			if i != 0 {
				nw[i][j] += M[i-1][j]
				c++
				if j != 0 {
					nw[i][j] += M[i-1][j-1]
					c++
				}
				
				if j != n-1 {
					nw[i][j] += M[i-1][j+1]
					c++
				}
			}
			if i != m-1 {
				nw[i][j] += M[i+1][j]
				c++
				if j != 0 {
					nw[i][j] += M[i+1][j-1]
					c++
				}
				
				if j != n-1 {
					nw[i][j] += M[i+1][j+1]
					c++
				}
			}
			
			if j != 0 {
				nw[i][j] += M[i][j-1]
				c++
			}
			
			if j != n-1 {
				nw[i][j] += M[i][j+1]
				c++
			}
			nw[i][j] = nw[i][j] / c
		}
	}
	return nw
}

func largeGroupPositions(S string) [][]int {
	if len(S) < 3 {
		return make([][]int, 0)
	}
	var res [][]int
	
	for i := 0; i != len(S); i++ {
	
	}
	
	return res
}

func pivotIndex(nums []int) int {
	if len(nums) < 3 {
		return -1
	}
	
	var left = 0
	var right = 0
	for i := 1; i != len(nums); i++ {
		right += nums[i]
	}
	
	if right == 0 {
		return 0
	}
	
	for i := 1; i != len(nums); i++ {
		left += nums[i-1]
		right -= nums[i]
		if left == right {
			return i
		}
	}
	
	return -1
}


func checkPossibility(nums []int) bool {
	var t = 0
	for  i := 1; i != len(nums); i++ {
		if nums[i] < nums[i-1]{
			t++
			if t > 1 {
				return false
			}
		}
	}
	return true
}

func day1(){
	var _ = strconv.Itoa // Ignore this comment. You can still use the package "strconv".
	
	var i uint64 = 4
	var d float64 = 4.0
	var s string = "HackerRank "
	
	scanner := bufio.NewScanner(os.Stdin)
	
	var o uint64 = scanner.Text()
	var x float64
	var str string
	// Read and save an integer, double, and String to your variables.
	
	o = i+o
	x = d +x
	str = s + str
	
	// Print the sum of both integer variables on a new line.
	fmt.Printf("%d\n%f\n%s\n", o,x,str)
}


func binaryGap(N int) int {
	var arr []int
	for N!=0 {
		arr = append(arr, N % 2)
		N = N / 2
	}
	sort.Reverse(arr)
}



func main() {
	var arr = [][]int{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}}
	fmt.Println(imageSmoother(arr))
}
