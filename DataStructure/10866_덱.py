#덱
from collections import deque
#입출력
from sys import stdin

#덱 선언
dq=deque()

#입력 
input = stdin.readline

#입력
T=int(input())

for _ in range(T):
    #명령어
    comm,*n=input().split()
    
    #앞 push
    if comm == 'push_front':
        dq.appendleft(int(n[0]))
    
    #뒤 push
    elif comm=='push_back':
        dq.append(int(n[0]))

    #앞 pop
    elif comm=='pop_front':
        print(dq.popleft() if len(dq) >0 else -1)
    
    #뒤 pop
    elif comm=='pop_back':
        print(dq.pop() if len(dq) >0 else -1)
    
    #size
    elif comm=='size':
        print(len(dq))

    #empty
    elif comm=='empty':
        print(1 if len(dq)==0 else 0)
    
    #front
    elif comm == 'front':
        print(dq[0] if len(dq)>0 else -1)
    
    #back
    elif comm=='back':
        print(dq[-1] if len(dq)>0 else -1)