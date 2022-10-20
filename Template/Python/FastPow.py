# https://www.acmicpc.net/problem/1629
import sys

def powWithMode(base, exp, mod):
  ret = 1
  while exp:
    if exp & 1:
      ret = (ret * base) % mod
    base = (base * base) % mod
    exp >>= 1

  return ret

a,b,c = map(int, sys.stdin.readline().split())

print(powWithMode(a, b, c))