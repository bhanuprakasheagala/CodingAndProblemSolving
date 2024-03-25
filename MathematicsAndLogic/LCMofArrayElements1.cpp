#include <iostream>
#include <vector>
#include <numeric>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
/*
The reduce function applies the lambda function to the elements of the list, cumulatively reducing the list to a single value (the LCM in this case).
*/
int LeastCommonMultiple(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 1, 
    [](int x, int y) {return (x*y)/gcd(x,y);});
}

int main() {
    
    std::vector<int> numbers = {2, 4, 6, 8};
    int lcm = LeastCommonMultiple(numbers);
    std::cout << "LCM of the given array elements: " << lcm << '\n';
    
    return 0;
}
