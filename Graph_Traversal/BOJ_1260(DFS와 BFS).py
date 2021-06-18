from collections import deque
n,m,v=map(int,input().split())
graph=[[] for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
visited=[False]*(n+1)
def DFS(graph,v,visited):
    visited[v]=True
    print(v,end=' ')
    for i in graph[v]:
        if not visited[i]:
            DFS(graph,i,visited)
DFS(graph,v,visited)
visited=[False]*(n+1)
print()
def BFS(graph,v,visited):
    queue=deque([v])
    visited[v]=True
    while queue:
        v=queue.popleft()
        print(v,end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True
BFS(graph,v,visited)