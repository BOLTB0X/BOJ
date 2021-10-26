#덱 이용
from collections import deque

n=int(input())
seq =list(map(int,input().split()))

#초기화
nge = [-1 for _ in range(n)]
stack=deque()

for i in range(n):
    #스택이 top이 다 더 커질 때까지 스택을 pop
    while stack and (stack[-1][0] < seq[i]):
        tmp,idx =stack.pop()
        nge[idx]=seq[i]
    stack.append([seq[i],i])

#출력
print(*nge)
