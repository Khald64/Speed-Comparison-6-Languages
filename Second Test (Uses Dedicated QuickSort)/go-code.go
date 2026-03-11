package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func quicksort(a []int) {
	if len(a) <= 1 {
		return
	}
	pivot := a[len(a)-1]
	i := 0
	for j := 0; j < len(a)-1; j++ {
		if a[j] <= pivot {
			a[i], a[j] = a[j], a[i]
			i++
		}
	}
	a[i], a[len(a)-1] = a[len(a)-1], a[i]
	quicksort(a[:i])
	quicksort(a[i+1:])
}

func main() {
	file, _ := os.Open("numbers.txt")
	defer file.Close()

	scanner := bufio.NewScanner(file)
	a := make([]int, 0, 10000000)

	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		a = append(a, n)
	}

	fmt.Println("Reading done.\nSorting...")
	start := time.Now()
	quicksort(a)
	ns := time.Since(start).Nanoseconds()

	fmt.Println(ns,"nanoseconds")
}

