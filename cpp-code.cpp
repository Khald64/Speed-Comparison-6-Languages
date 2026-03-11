#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

int main() {
    std::ifstream file("numbers.txt");
    std::vector<int> a;
    a.reserve(10000000);

    int x;
    while (file >> x) a.push_back(x);
	std::cout << "Reading done.\nSorting..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::high_resolution_clock::now();
	
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds";
}