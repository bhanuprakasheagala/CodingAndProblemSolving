/*
Source: https://en.wikipedia.org/wiki/Primality_test

All primes greater than 3 are of the form 6k+i for a non negative integer k and
i belongs to {1,5}. It's because:
Every integer is of the form 6k+i for a positive integer k and
i belongs to {1,2,3,4,5}.
Since 2 divides 6k, 6k+2, and 6k+4, And 3 divides 6k and 6k+3, the only possible
remainders mod 6 for a prime greater than 3 are 1 and 5.

Hence, Check if n is divisible by 2 or 3. Then check through all numbers of the form
6k+1 and 6k+5 which are `<=sqrt(n)`.
*/

#include <iostream>

bool isPrime(int n) {
    if(n == 2 || n == 3)
        return true;
    if(n <= 1 || n%2 == 0 || n%3 == 0)
        return false;
    for(int i=5; i*i <= n; i += 6) {
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    std::cin >> n;

    if(isPrime(n)) {
        std::cout << n << " is a Prime number\n";
    }
    else {
        std::cout << n << " is not a Prime number\n";
    }

    return 0;
}