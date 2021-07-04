from collections import deque
MAX=100001
t=[0]*MAX

def bfs(n,k):
    que=deque()
    que.append(n)
    t[n]=1
    while que:
        x=que.popleft()
        if (x==k):
            return (t[x]-1)
        for next in (x-1,x+1,2*x):
            if (next>=0 and next<MAX and t[next]==0):
                t[next]=t[x]+1
                que.append(next)

n,k=map(int,input().split())
answer=bfs(n,k)
print(answer)         