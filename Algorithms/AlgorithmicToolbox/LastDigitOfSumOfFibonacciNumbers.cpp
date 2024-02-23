#include <iostream>
#include <vector>

int lastDigitOfSumOfFibonacciNumbers(long long n) {
    std::vector<int> fibonacci(n+1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    int sum_last_digits = 1;
    for(int i=2; i<=n; ++i) {
        fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%10;
        sum_last_digits = (sum_last_digits + fibonacci[i])%10;
    }

    return sum_last_digits;
}

int main()
{
    long long n;
    std::cout << "Enter the positive integer: ";
    std::cin >> n;

    int sum_last_digit = lastDigitOfSumOfFibonacciNumbers(n);

    std::cout << "Last digit of the sum of Fibonacci(" << n << ") is: " << sum_last_digit << '\n';

    return 0;
}