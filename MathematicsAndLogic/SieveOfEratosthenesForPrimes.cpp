#include <iostream>

void SieveOfEratosthenes(int n) {
    // For each number 0 to n, to store whether it's prime or not
    bool prime[n+1];

    // Initially mark all entries as prime
    memset(prime, true, sizeof(prime));

    for(int p=2; p*p<=n; ++p) {
        // If prime[p] not changed, it's a prime
        if(prime[p] == true) {
            /*
            Update all multiples of p greater than or equal to the square of it.
            Numbers which are multiple of p and are less than p^2 are already marked.
            */
            for(int i=p*p; i<=n; i+=p) {
                prime[i] = false;
            }
        }
    }
    std::cout << "Prime numbers up to " << n << " are:\n";
    for(int p=2; p<=n; ++p) {
        if(prime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << '\n';
}

int main()
{
    int n;
    std::cin >> n;
    SieveOfEratosthenes(n);

    return 0;
}