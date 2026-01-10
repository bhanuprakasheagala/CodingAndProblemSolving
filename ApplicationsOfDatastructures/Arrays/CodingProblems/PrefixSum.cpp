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
    std::vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    std::cout << "Prefix Sum Array: ";
    for (const auto& sum : prefixSum) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}