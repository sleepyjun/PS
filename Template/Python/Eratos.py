# https://www.acmicpc.net/problem/1929
import sys

MAX = 1_000_000
isPrime = [True for i in range(MAX+1)]
isPrime[0] = isPrime[1] = False
limit = int(MAX ** 0.5) + 1

for i in range(2, limit):
  if isPrime[i] == True:
    for j in range(i*i, MAX+1, i):
      isPrime[j] = False

#! primes = [prime for prime in range(2, MAX+1) if isPrime[i] == True]
m, n = map(int, sys.stdin.readline().split())

for i in range(m, n+1):
  if isPrime[i] == True:
    print(i)
