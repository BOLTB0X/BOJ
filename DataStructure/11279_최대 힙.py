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
            print(-1 * heapq.heappop(heap))
        else:
            print('0')
    else:
        heapq.heappush(heap, -x)
