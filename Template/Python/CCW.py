# https://www.acmicpc.net/status?user_id=sestrik&problem_id=11758&from_mine=1
import sys

def ccw(p1, p2, p3):
  temp = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1]
  temp -= p1[0] * p3[1] + p2[0] * p1[1] + p3[0] * p2[1]

  if temp > 0:
    return 1
  elif temp < 0:
    return -1
  return 0

p1 = tuple(map(int, sys.stdin.readline().split()))
p2 = tuple(map(int, sys.stdin.readline().split()))
p3 = tuple(map(int, sys.stdin.readline().split()))

print(ccw(p1, p2 ,p3))