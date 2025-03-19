// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

void SieveOfEratosthenes(int n)
{
    auto start = high_resolution_clock::now();

    vector<bool> prime(n + 1, true); // Heap allocation because too big for stack to handle

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "It took " << (duration.count() / 1e6) << " seconds" << endl;

    size_t cnt = count(prime.begin() + 2, prime.end(), true);
    cout << cnt << " ";
}

int main() {
    size_t size = 1'000'000'00;

    std::cout << "outside class: " << std::endl;
    SieveOfEratosthenes(size);

    return 0;
}
