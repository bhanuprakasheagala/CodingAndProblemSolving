#include <iostream>
#include <vector>

std::vector<int> rangeSumQueries(const std::vector<int>& arr, const std::vector<std::vector<int>>& queries) {
    int n = arr.size();
    std::vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    // Compute prefix sums
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    std::vector<int> results;
    
    // Process each query
    for (const auto& query : queries) {
        int l = query[0];
        int r = query[1];
        int sum = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
        results.push_back(sum);
    }

    return results;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the number of queries: ";
    int q;
    std::cin >> q;
    std::vector<std::vector<int>> queries(q, std::vector<int>(2));
    std::cout << "Enter the queries (l r) 0-based indices:\n";
    for (int i = 0; i < q; ++i) {
        std::cin >> queries[i][0] >> queries[i][1];
    }

    std::vector<int> prefixSum = rangeSumQueries(arr, queries);

    std::cout << "Results of the queries:\n";
    for (const auto& sum : prefixSum) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}