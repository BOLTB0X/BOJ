#DFS와 BFS
from collections import deque
n,m,v=map(int,input().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
visited=[False]*(n+1)

def dfs(graph,v,vistited):
    vistited[v]=True
    print(v,end=' ')
    for i in graph[v]:
        if not vistited[i]:
            dfs(graph,i,vistited)
dfs(graph,v,visited)
visited=[False]*(n+1)

print()
def bfs(graph,v,visited):
    queue=deque([v])
    visited[v]=True
    while queue:
        a=queue.popleft()
        print(a,end=' ')
        for i in graph[a]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True
bfs(graph,v,visited)




