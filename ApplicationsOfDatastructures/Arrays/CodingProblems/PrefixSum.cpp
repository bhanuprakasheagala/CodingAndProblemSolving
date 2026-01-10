#include <iostream>
#include <vector>


int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // In-place computation of prefix sums
    for (int i = 1; i < n; ++i) {
        arr[i] = arr[i - 1] + arr[i];
    }

    std::cout << "Prefix Sum Array: ";
    for (const auto& sum : arr) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}