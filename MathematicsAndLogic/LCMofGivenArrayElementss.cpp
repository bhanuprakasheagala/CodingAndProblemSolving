#include <iostream>
typedef long long int ll;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll findLCMofAnArray(int arr[], int n) {
    int res = arr[0];
    for(int i=1; i<n; ++i) {
        res = ((arr[i]*res)/gcd(arr[i], res));
    }
    
    return res;
}

int main()
{
    //std::cout<<"Hello World";
    int arr[] = {2, 7, 3, 9, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%lld", findLCMofAnArray(arr, n));

    return 0;
}
