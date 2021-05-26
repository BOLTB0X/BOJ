#바이러스
from collections import deque
n=int(input())
m=int(input())
graph=[[]*i for i in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
visited=[False]*(n+1)
cnt=0
def bfs(graph,visited,cnt):
    que=deque([1])
    visited[1]=True
    while que:
        x=que.popleft()
        if not visited[x]:
            visited[x]=True
            cnt+=1
        for i in graph[x]:
            if not visited[i]:
                que.append(i)
                visited[i]=True
                cnt+=1
    return cnt
print(bfs(graph,visited,cnt))