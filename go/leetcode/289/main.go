package main

func gameOfLife(board [][]int) {
	m := len(board)
	if m == 0 {
		return
	}
	n := len(board[0])
	res := make([][]int, m)
	for i := 0; i < m; i++ {
		res[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			lives := 0
			if i > 0 {
				if j > 0 {
					lives += board[i-1][j-1]
				}
				lives += board[i-1][j]
				if j < n-1 {
					lives += board[i-1][j+1]
				}
			}
			if j > 0 {
				lives += board[i][j-1]
			}
			if j < n-1 {
				lives += board[i][j+1]
			}
			if i < m-1 {
				if j > 0 {
					lives += board[i+1][j-1]
				}
				lives += board[i+1][j]
				if j < n-1 {
					lives += board[i+1][j+1]
				}
			}
			if board[i][j] == 1 {
				if lives >1 && lives < 4{
					res[i][j] = 1
				}
			}else	if board[i][j] == 0 && lives == 3 {
				res[i][j] = 1
			}
		}
	}
	for i := 0; i < m; i++{
		board[i] = res[i]
	}
}
