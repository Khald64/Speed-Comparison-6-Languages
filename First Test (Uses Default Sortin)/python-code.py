import time

with open("numbers.txt") as f:
    a = [int(line) for line in f]
print("Reading done.\nSorting....");
start = time.perf_counter_ns()
a.sort()
ns = time.perf_counter_ns() - start

print(ns,"nanoseconds")