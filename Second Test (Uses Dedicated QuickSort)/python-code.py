import time

def quicksort(a):
    if len(a) <= 1:
        return a
    pivot = a[-1]
    left = [x for x in a[:-1] if x <= pivot]
    right = [x for x in a[:-1] if x > pivot]
    return quicksort(left) + [pivot] + quicksort(right)

with open("numbers.txt") as f:
    a = [int(line) for line in f]
print("Reading done.\nSorting....");
start = time.perf_counter_ns()
a = quicksort(a)
ns = time.perf_counter_ns() - start

print(ns,"nanoseconds")
