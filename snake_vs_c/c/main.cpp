#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

void sieve_of_eratosthenes(int n)
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

    sieve_of_eratosthenes(size);

    return 0;
}
