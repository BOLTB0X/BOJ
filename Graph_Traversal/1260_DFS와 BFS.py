from collections import deque
#입출력
from sys import stdin
#입력 
input = stdin.readline

#깊이우선탐색
def DFS(graph,v,visited):
    visited[v]=True
    print(v,end=' ')
    for i in graph[v]:
        if not visited[i]:
            DFS(graph,i,visited)

#너비우선탐색
def BFS(graph,v,visited):
    que=deque([v])
    visited[v]=True
    while que:
        v=que.popleft()
        print(v,end=' ')
        for i in graph[v]:
            if not visited[i]:
                que.append(i)
                visited[i]=True

n,m,v=map(int,input().split())
graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()

DFS(graph,v,visited)
print()

visited=[False]*(n+1)
BFS(graph,v,visited)