# https://www.acmicpc.net/problem/1753
import sys, heapq

prev = [-1 for _ in range(20_001)]
def track(node, step):
  if prev[node] == -1:
    print(step)
    print(node, end=' ')
    return
  track(prev[node], step+1)
  print(node, end=' ')

MAX = 1_000_000_000
V, E = map(int, sys.stdin.readline().split())
start = int(sys.stdin.readline())
adj = [[] for _ in range(20_001)]
dist = [MAX for _ in range(20_001)]
pq = []


for _ in range(E):
  u, v, w = map(int, sys.stdin.readline().split())
  adj[u].append((v, w))

heapq.heappush(pq, (0, start))

while pq:
  cost, curr = pq[0]
  heapq.heappop(pq)

  if dist[curr] < cost:
    continue

  for next, d in adj[curr]:
    d += cost
    if dist[next] > d:
      dist[next] = d
      prev[next] = curr
      heapq.heappush(pq, (dist[next], next))


for i in range(1, V+1):
  if i == start:
    print(0)
  else:
    print(("INF" if dist[i] == MAX else dist[i]))