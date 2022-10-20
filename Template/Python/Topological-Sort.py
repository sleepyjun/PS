# https://www.acmicpc.net/problem/2623
import sys

adj = [[] for _ in range(1001)]
prev = [0 for _ in range(1001)]
res = []
n, m = map(int, sys.stdin.readline().split())

for _ in range(m):
  arr = list(map(int, sys.stdin.readline().split()))[1:]
  if not arr:
    continue
  pre = arr[0]
  for curr in arr[1:]:
    adj[pre].append(curr)
    prev[curr] += 1
    pre = curr

q = []
for i in range(1, n+1):
  if prev[i] == 0:
    q.append(i)

flag = False
for i in range(1, n+1):
  if not q:
    flag = True
    break
  
  curr = q.pop(0)
  res.append(curr)
  for n in adj[curr]:
    prev[n] -= 1
    if prev[n] == 0:
      q.append(n)

if flag:
  print(0)
else:
  for r in res:
    print(r)
