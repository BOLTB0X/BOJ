#큐
import queue
#입출력
from sys import stdin

#큐 선언
q=queue.Queue()
#입력 
input = stdin.readline

T=int(input())
for i in range(T):
    #명령어 입력
    comm,*n=input().split()

    #push
    if comm=='push':
        q.put(int(n[0]))
    
    #pop
    elif comm=='pop':
        print(q.get() if not q.empty() else -1)
    
    #size
    elif comm=='size':
        print(q.qsize())
    
    #empty
    elif comm=='empty':
        print(1 if q.empty() else 0)
    
    #front
    elif comm=='front':
        print(q.queue[0] if not q.empty() else -1)
    
    #back
    elif comm=='back':
        print(q.queue[-1] if not q.empty() else -1)