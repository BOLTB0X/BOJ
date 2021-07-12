#BFS
from collections import deque
n,m=map(int,input().split())

graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)
answer=0

for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def BFS(graph,visited,v):
    que=deque()
    que.append(v)
    while que:
        x=que.popleft()
        
        for i in graph[x]:
            if visited[i]==False:
                que.append(i)
                visited[i]=True

for i in range(1,len(graph)):
    if visited[i]==False:
        BFS(graph,visited,i)
        answer+=1
print(answer)