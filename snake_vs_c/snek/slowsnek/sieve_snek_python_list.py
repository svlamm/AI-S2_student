import math
import time

size = 1_000_000_00
primes = [True] * size

start = time.time()

primes[0] = False
primes[1] = False

# Mark even numbers (except 2) as non-prime
for i in range(4, size, 2):
    primes[i] = False

# Sieve of Eratosthenes
for i in range(3, math.isqrt(size) + 1, 2):
    if primes[i]:
        for j in range(i * i, size, i):
            primes[j] = False

print("time:", time.time() - start)

# Count prime occurrences
prime_count = sum(primes)
non_prime_count = size - prime_count
print([non_prime_count, prime_count])