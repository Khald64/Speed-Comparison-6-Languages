#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>

void quicksort(std::vector<int>& a, int left, int right) {
    if (left >= right) return;
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[right]);
    int p = i + 1;
    quicksort(a, left, p - 1);
    quicksort(a, p + 1, right);
}

int main() {
    std::ifstream file("numbers.txt");
    std::vector<int> a;
    a.reserve(10000000);

    int x;
    while (file >> x) a.push_back(x);
	std::cout << "Reading done.\nSorting..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(a, 0, a.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds";
}
