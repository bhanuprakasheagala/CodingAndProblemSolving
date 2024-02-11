#include <iostream>
#include <vector>
void merge(std::vector<int>& arr, int low, int mid, int high) {
    int m = mid - low + 1;
    int n = high - mid;

    std::vector<int> L(m);
    std::vector<int> R(n);

    for(int i=0; i<m; ++i)
        L[i] = arr[low+i];
    for(int j=0; j<n; ++j)
        R[j] = arr[mid+1+j];
    
    int i=0, j=0, k=low;
    while(i<m && j<n) {
        if(L[i] <= R[j]) {
            arr[k] = L[i++];
        }
        else {
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < m) {
        arr[k++] = L[i++];
    }
    while(j < n) {
        arr[k++] = R[j++];
    }
}
void mergeSort(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void Sort(std::vector<int>& arr, int n) {
    int l = 0;
    int r = n-1;
    mergeSort(arr, l, r);
    for(int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    Sort(arr, n);
}