package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"time"
)

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
	sort.Ints(a)
	ns := time.Since(start).Nanoseconds()

	fmt.Println(ns,"nanoseconds")
}