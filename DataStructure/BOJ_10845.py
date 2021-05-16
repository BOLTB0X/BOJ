#큐 10845 
import queue
import sys
q=queue.Queue()
input=lambda :sys.stdin.readline().rstrip()
T=int(input())
for i in range(T):
    comm,*n=input().split()
    if comm=='push':
        q.put(int(n[0]))
    elif comm=='pop':
        print(q.get() if not q.empty() else -1)
    elif comm=='size':
        print(q.qsize())
    elif comm=='empty':
        print(1 if q.empty() else 0)
    elif comm=='front':
        print(q.queue[0] if not q.empty() else -1)
    elif comm=='back':
        print(q.queue[-1] if not q.empty() else -1)
