# https://www.acmicpc.net/problem/11438

import sys, math
sys.setrecursionlimit(10**5)

MAX_NODE = 100_000
MAX_HEIGHT = math.ceil(math.log2(MAX_NODE))
parent = [[-1 for _ in range(MAX_HEIGHT+1)] for _ in range(MAX_NODE+1)]
# parent[i][k] = i's 2&k st parent
depth = [-1 for _ in range(MAX_NODE+1)]
adj = [[] for _ in range(MAX_NODE+1)]

def makeTree(curr):
  for nextNode in adj[curr]:
    if depth[nextNode] == -1:
      parent[nextNode][0] = curr
      depth[nextNode] = depth[curr] + 1
      makeTree(nextNode)

n = int(sys.stdin.readline())
for _ in range(n-1):
  u, v = map(int, sys.stdin.readline().split())
  adj[u].append(v)
  adj[v].append(u)

depth[1] = 0
makeTree(1)

for k in range(MAX_HEIGHT+1):
  for i in range(1, n+1):
    if parent[i][k] != -1:
      parent[i][k+1] = parent[parent[i][k]][k]

m = int(sys.stdin.readline())
for _ in range(m):
  a, b = map(int, sys.stdin.readline().split())
  if depth[a] < depth[b]:
    a, b = b, a
  diff = depth[a] - depth[b]
  i = 0

  while diff:
    if diff % 2:
      a = parent[a][i]
    diff //= 2
    i += 1
  
  if a != b:
    for i in range(MAX_HEIGHT, -1, -1):
      if parent[a][i] != -1 and parent[a][i] != parent[b][i]:
        a = parent[a][i]
        b = parent[b][i]
    a = parent[a][0]
  
  print(a)