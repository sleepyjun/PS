# https://www.acmicpc.net/problem/1922
import sys

p = [-1 for _ in range(1001)]

def find(a):
  if p[a] < 0:
    return a
  p[a] = find(p[a])
  return p[a]

def union(a, b):
  a = find(a)
  b = find(b)

  if a == b:
    return False

  p[b] = a
  return True

edge = []
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

for _ in range(m):
  a, b, c = map(int, sys.stdin.readline().split())
  edge.append((a,b,c))

edge.sort(key=lambda x: x[2])

result, cnt = 0, 0
for a, b, c in edge:
  if union(a, b) == True:
    result += c
    cnt += 1
    if cnt == n-1:
      break;

print(result)