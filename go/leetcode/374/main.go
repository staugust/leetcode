/*
Copyright 2020 Alipay.Inc.
*/

package main

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */
func guess(num int) int {
	return 0
}

func guessN(h, t int) int {
	mid := (h + t) / 2
	if guess(mid) == 0 {
		return mid
	} else if guess(mid) < 0 {
		return guessN(h, mid-1)
	}
	return guessN(mid+1, t)
}

func guessNumber(n int) int {
	return guessN(0, n)
}

func main() {

}
