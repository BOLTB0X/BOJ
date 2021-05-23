#특정 거리의 도시 찾기
from collections import deque
n,m,k,x=map(int,input().split()) #여기서 k는 거리
graph=[[] for i in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[a].sort()
visited=[False]*(n+1)
distance=[-1 for _ in range(n+1)]
distance[x]=0
def bfs(graph,x,visited,distance):
    que=deque([x])
    while que:
        a=que.popleft()
        visited[a]=True
        for i in graph[a]:
            if not visited[i] and distance[i]==-1:
                que.append(i)
                distance[i]=distance[a]+1
bfs(graph,x,visited,distance)
check=False
for i in range(1,n+1):
    if distance[i]==k:
        print(i)
        check=True
if check==False:
    print(-1)