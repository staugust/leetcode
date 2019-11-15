package main

/*
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/

func minDominoRotations(A []int, B []int) int {
	dA := A[0]
	dB := B[0]
	var pA = true
	var pB = true
	var rA = 0
	var rB = 0

	if dA == dB {
		for i := 0; i < len(A); i++ {
			if pA {
				if A[i] != dA {
					if B[i] == dA {
						rA += 1
					} else {
						return -1
					}
				}
			}
			if pB {
				if B[i] != dA {
					if A[i] != dA {
						return -1
					} else {
						rB += 1
					}
				}
			}
		}
		r := len(A)
		if pA && r > rA {
			r = rA
		}
		if pB && r > rB {
			r = rB
		}
		if r == len(A) {
			return -1
		}
		return r
	}

	var prA = true
	var prB = true
	var rrA = 0
	var rrB = 0

	for i := 0; i < len(A); i++ {
		if pA {
			if A[i] != dA {
				if B[i] != dA {
					pA = false
				} else {
					rA += 1
				}
			}
		}
		if pB {
			if B[i] != dB {
				if A[i] != dB {
					pB = false
				} else {
					rB += 1
				}
			}
		}

		if prA {
			if B[i] != dA {
				if A[i] != dA {
					prA = false
				} else {
					rrA += 1
				}
			}
		}

		if prB {
			if A[i] != dB {
				if B[i] != dB {
					prB = false
				} else {
					rrB += 1
				}
			}
		}
	}
	var r = len(A)
	if pA {
		if rA < r {
			r = rA
		}
	}
	if pB {
		if rB < r {
			r = rB
		}
	}
	if prA {
		if rrA < r {
			r = rrA
		}
	}

	if prB {
		if rrB < r {
			r = rrB
		}
	}

	if r == len(A) {
		return -1
	}
	return r
}

func main() {

}
