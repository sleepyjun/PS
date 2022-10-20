# https://www.acmicpc.net/problem/11724
import sys

visited = [False for _ in range(1001)]
adj = [[] for _ in range(1001)]

def dfs(curr):
  visited[curr] = True

  for next in adj[curr]:
    if visited[next] == False:
      dfs(next)

n, m = map(int, sys.stdin.readline().split())

for _ in range(m):
  u, v = map(int, sys.stdin.readline().split())
  adj[u].append(v)
  adj[v].append(u)

answer = 0
for u in range(1, n+1):
  if visited[u] == False:
    answer += 1
    dfs(u)

print(answer)