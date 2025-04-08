import time

def sieve_of_eratosthenes(n):
    start = time.time()

    # Create a boolean array "prime[0..n]" and initialize all entries as True.
    prime = [True] * (n + 1)

    p = 2
    while p * p <= n:
        if prime[p]:
            # Update all multiples of p
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1

    duration = time.time() - start
    print(f"It took {duration} seconds")

    # Count and print number of primes
    count = sum(1 for p in range(2, n + 1) if prime[p])
    print(count)

# Driver code
if __name__ == "__main__":
    n = 1_000_000_00
    sieve_of_eratosthenes(n)
