# https://www.acmicpc.net/problem/2609
import math, sys

def gcd(a, b):
  if a < b:
    a, b = b, a
  while b:
    a, b = b, a%b
  return a

def lcm(a, b):
  return a * b // gcd(a, b)

a, b = map(int, sys.stdin.readline().split())

# print(math.gcd(a,b))
# print(math.lcm(a,b))
print(gcd(a,b))
print(lcm(a,b))
