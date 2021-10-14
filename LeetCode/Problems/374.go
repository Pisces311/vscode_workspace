/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

package main

func guess(num int) int

func guessNumber(n int) int {
	l, r := 1, n
	var ans int
	for l <= r {
		mid := (l + r) / 2
		ret := guess(mid)
		if ret == 1 {
			l = mid + 1
		} else if ret == -1 {
			r = mid - 1
		} else {
			ans = mid
			break
		}
	}
	return ans
}
