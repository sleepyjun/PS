# https://www.acmicpc.net/problem/10830
import sys

MOD = 1000
n, b = map(int, sys.stdin.readline().split())
temp = [[0 for i in range(n)] for j in range(n)]

def mulMatrix(dest, src):
  for i in range(0, n):
    for j in range(0, n):
      temp[i][j] = 0
      for k in range(0, n):
        temp[i][j] += (dest[i][k] * src[k][j])
      temp[i][j] %= 1000
  
  for i in range(0, n):
    for j in range(0, n):
      dest[i][j] = temp[i][j]


base = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
res = [[1 if i == j else 0 for i in range(n)] for j in range(n)]

while b:
  if b&1:
    mulMatrix(res, base)
  mulMatrix(base, base)
  b >>= 1

for i in range(0, n):
  for j in range(0, n):
    print(res[i][j]%MOD, end=' ')
  print()  