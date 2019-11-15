package main

import "fmt"

/*
https://leetcode.com/problems/queens-that-can-attack-the-king/
*/
func queensAttacktheKing(queens [][]int, king []int) [][]int {
	arr := make(map[int][]int, 8)
	for i := 0; i < 8; i++ {
		arr[i] = make([]int, 8)
	}
	for _, val := range queens {
		arr[val[0]][val[1]] = 1
	}

	x := king[0]
	y := king[1]
	res := make([][]int, 0)
	for i := x - 1; i >= 0; i-- {
		if arr[i][y] == 1 {
			res = append(res, []int{i, y})
			break
		}
	}
	for i := x + 1; i < 8; i++ {
		if arr[i][y] == 1 {
			res = append(res, []int{i, y})
			break
		}
	}
	for j := y - 1; j >= 0; j-- {
		if arr[x][j] == 1 {
			res = append(res, []int{x, j})
			break
		}
	}
	for j := y + 1; j < 8; j++ {
		if arr[x][j] == 1 {
			res = append(res, []int{x, j})
			break
		}
	}
	i := x - 1
	j := y - 1
	for i >= 0 && j >= 0 {
		if arr[i][j] == 1 {
			res = append(res, []int{i, j})
			break
		}
		i -= 1
		j -= 1
	}

	i = x + 1
	j = y + 1
	for i < 8 && j < 8 {
		if arr[i][j] == 1 {
			res = append(res, []int{i, j})
			break
		}
		i += 1
		j += 1
	}
	i = x + 1
	j = y - 1
	for i < 8 && j >= 0 {
		if arr[i][j] == 1 {
			res = append(res, []int{i, j})
			break
		}
		i += 1
		j -= 1
	}
	i = x - 1
	j = y + 1
	for i >= 0 && j < 8 {
		if arr[i][j] == 1 {
			res = append(res, []int{i, j})
			break
		}
		i -= 1
		j += 1
	}
	return res
}

func main() {
	queens := [][]int{{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}}
	king := []int{0, 0}
	fmt.Println(queensAttacktheKing(queens, king))

}
