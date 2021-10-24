from collections import deque
n=int(input())
seq =list(map(int,input().split()))

nge = [-1 for _ in range(n)]
stack=deque()

for i in range(n):
    while stack and (stack[-1][0] < seq[i]):
        tmp,idx =stack.pop()
        nge[idx]=seq[i]
    stack.append([seq[i],i])

print(*nge)