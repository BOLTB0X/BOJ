import heapq
#입출력
from sys import stdin
#입력 
input = stdin.readline

T = int(input())
heap = []

for _ in range(T):
    x = int(input())
    if x == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (abs(x),x))