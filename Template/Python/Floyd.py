# https://www.acmicpc.net/problem/11780
import sys

INF = 100_000_000
dp = [[0 if i == j else INF for i in range(101)] for j in range(101)]
pathInfo = [[-1 for _ in range(101)] for _ in range(101)]
path = []

def find(s, e):
  if pathInfo[s][e] != -1:
    find(s, pathInfo[s][e])
    path.append(pathInfo[s][e])
    find(pathInfo[s][e], e)

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

for _ in range(m):
  u, v, w = map(int, sys.stdin.readline().split())
  dp[u][v] = min(dp[u][v], w)

for k in range(1, n+1):
  for i in range(1, n+1):
    for j in range(1, n+1):
      cost = dp[i][k] + dp[k][j];
      if dp[i][j] > cost:
        dp[i][j] = cost
        pathInfo[i][j] = k

for i in range(1, n+1):
  for j in range(1, n+1):
    print(dp[i][j] if dp[i][j] != INF else 0, end=' ')
  print()

for i in range(1, n+1):
  for j in range(1, n+1):
    path.clear()
    if (i == j or dp[i][j] == INF):
      print(0, end=' ')
    else:
      path.append(i)
      find(i, j)
      path.append(j)
      print(len(path), end=' ')
      for p in path:
        print(p, end=' ')
    print()
