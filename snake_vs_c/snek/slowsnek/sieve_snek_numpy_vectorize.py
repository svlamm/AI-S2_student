import math
import time

import numpy as np

size = 1_000_000_00
primes = np.ones(size, dtype=bool)

start = time.time()

primes[0] = False
primes[1] = False

primes[2 * 2::2] = 0


for i in range(3, math.ceil(math.sqrt(size)), 2):
    if primes[i]:
        # begin bij pow of i, en elke i verder is een multiple
        primes[i * i::i] = 0

print("time: ", time.time() - start)
unique, counts = np.unique(primes, return_counts=True)

print(counts)