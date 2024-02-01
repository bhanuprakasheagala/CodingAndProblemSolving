#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr, int n) {
    for(int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}
int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; ++j) {
        if(arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(std::vector<int>& arr, int l, int r) {
    if(l < r) {
        int pivotPoint = partition(arr, l, r);
        quickSort(arr, l, pivotPoint-1);
        quickSort(arr, pivotPoint+1, r);
    }
}
int main() {
    std::vector<int> input;
    int num;
    for(int i=0; i<8; ++i){
        std::cin >> num;
        input.push_back(num);
    }
    int n = input.size();
    printArray(input, n);
    int l = 0, r = n-1;
    quickSort(input, l, r);
    printArray(input, n);

    return 0;
}