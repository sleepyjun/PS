# https://www.acmicpc.net/problem/2188
import sys

adj = [[] for _ in range(201)]
visited = [False for _ in range(201)]
aGroup = [-1 for _ in range(201)]
bGroup = [-1 for _ in range(201)]

def dfs(a):
  visited[a] = True
  for b in adj[a]:
    if bGroup[b] == -1 or not visited[bGroup[b]] and dfs(bGroup[b]):
      aGroup[a] = b
      bGroup[b] = a
      return True

  return False

n, m = map(int, sys.stdin.readline().split())

for i in range(n):
  arr = list(map(int, sys.stdin.readline().split()))[1:]
  adj[i].extend(arr)

match = 0
for i in range(n):
  if aGroup[i] == -1:
    for j in range(201):
      visited[j] = False
    if dfs(i):
      match += 1

print(match)