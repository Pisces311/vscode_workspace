package main

import "sync"

func merge(a []int, mid int) {

}

func mergeSort(a []int) {
	n := len(a)
	if n == 1 {
		return
	}
	mid := n / 2
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		mergeSort(a[:mid])
	}()
	mergeSort(a[mid:])
	wg.Wait()
	merge(a, mid)
}

func main() {

}
