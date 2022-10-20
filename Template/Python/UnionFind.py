# https://www.acmicpc.net/problem/4195
import sys
from collections import defaultdict

def find(a, p):
  if p[a] < 0:
    return a
  p[a] = find(p[a], p)
  return p[a]

def union(a ,b, p):
  a = find(a, p)
  b = find(b, p)

  if a == b:
    print(abs(p[a]))
    return

  p[a] += p[b]
  p[b] = a
  print(abs(p[a]))
  return

n = int(sys.stdin.readline())

for _ in range(n):
  idx = 1
  m = int(sys.stdin.readline())
  dic = defaultdict(int)
  p = [-1 for _ in range(200_001)]
  
  for _ in range(m):
    a, b = sys.stdin.readline().split()
    if dic[a] == 0:
      dic[a] = idx
      idx += 1
    if dic[b] == 0:
      dic[b] = idx
      idx += 1
    union(dic[a], dic[b], p)
  
  del(dic)
  del(p)