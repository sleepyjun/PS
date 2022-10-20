# https://www.acmicpc.net/problem/2178
import sys

DIR = [[1, 0], [0, 1], [-1, 0], [0, -1]]
n, m = map(int, sys.stdin.readline().split())
maze = [[0] * m for _ in range(n)]

def possible(y, x):
  return (0 <= y and y < n) and (0 <= x and x < m)

def bfs():
  ret = 1
  q = [(0,0)]
  maze[0][0] = 0

  while q:
    qSize = len(q)
    for _ in range(qSize):
      curr = q.pop(0)
      if curr[0] == n-1 and curr[1] == m-1:
        return ret
      
      for dy, dx in DIR:
        ny, nx = curr[0] + dy, curr[1] + dx

        if possible(ny, nx) == False:
          continue
        if maze[ny][nx] == 0:
          continue
        maze[ny][nx] = 0
        q.append((ny, nx))
    ret += 1

  return ret



for y in range(n):
  line = sys.stdin.readline().strip()
  for x, num in enumerate(line):
    maze[y][x] = int(num)

print(bfs())