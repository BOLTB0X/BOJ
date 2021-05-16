from collections import deque
import sys
input=lambda :sys.stdin.readline().rstrip()
dq=deque()
T=int(input())
for _ in range(T):
    comm,*n=input().split()
    if comm == 'push_front':
        dq.appendleft(int(n[0]))
    elif comm=='push_back':
        dq.append(int(n[0]))
    elif comm=='pop_front':
        print(dq.popleft() if len(dq) >0 else -1)
    elif comm=='pop_back':
        print(dq.pop() if len(dq) >0 else -1)
    elif comm=='size':
        print(len(dq))
    elif comm=='empty':
        print(1 if len(dq)==0 else 0)
    elif comm == 'front':
        print(dq[0] if len(dq)>0 else -1)
    elif comm=='back':
        print(dq[-1] if len(dq)>0 else -1)