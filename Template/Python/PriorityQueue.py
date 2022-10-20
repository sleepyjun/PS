# https://www.acmicpc.net/problem/2696
import heapq, sys
# heapq는 최소힙 / 최소 요소가 가장 앞에 있음
t = int(sys.stdin.readline())

for _ in range(t):
  m = int(sys.stdin.readline())
  line = m//10 + (1 if m%10 else 0)
  arr, answer, minHeap, maxHeap = [], [], [], []

  for _ in range(line):
    arr.extend(map(int, sys.stdin.readline().split()))

  for idx, x in enumerate(arr, start=1):
    if len(minHeap) == len(maxHeap):
      heapq.heappush(maxHeap, -x)
    else:
      heapq.heappush(minHeap, x)
    
    if minHeap and maxHeap:
      a, b = -maxHeap[0], minHeap[0]
      if a > b:
        heapq.heappushpop(maxHeap, -b)
        heapq.heappushpop(minHeap, a)
    if idx % 2:
      answer.append(-maxHeap[0])
  # 홀수 개수일때 최대힙의 첫 요소가 중앙값
  # 최대힙에는 제일 작은수 ~ 중앙값
  # 최소힙에는 중앙값 다음 수 ~ 제일 큰 수 유지
  size = len(answer)
  print(size)
  for i in range(size):
    print(answer[i], end='')
    if (i+1) % 10:
       print(' ', end='')
    else:
      print()
  if size % 10:
    print()
