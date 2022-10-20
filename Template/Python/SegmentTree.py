# https://www.acmicpc.net/problem/2042
import sys

MAX = 1_000_000
arr = [0 for _ in range(2*MAX)]
n, m, k = map(int, sys.stdin.readline().split())

def init():
  for i in range(n-1, 0, -1):
    arr[i] = arr[i * 2] + arr[i * 2 + 1]

def update(i, v):
  i += n
  arr[i] = v
  while i >= 1:
    i //= 2
    arr[i] = arr[i * 2] + arr[i * 2 + 1]

# [1, r)
def query(l, r):
  ret = 0
  l += n
  r += n

  while l < r:
    if l%2:
      ret += arr[l]
      l += 1
    if r%2:
      r -= 1
      ret += arr[r]
    l //= 2
    r //= 2
  
  return ret

for i in range(n):
  arr[i+n] = int(sys.stdin.readline())
init()

for _ in range(m+k):
  a, b, c = map(int, sys.stdin.readline().split())

  if a == 1:
    update(b-1, c)
  elif a == 2:
    print(query(b-1, c))
