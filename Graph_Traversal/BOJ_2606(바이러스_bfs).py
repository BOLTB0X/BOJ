#BFS 풀이
from collections import deque
n=int(input())
m=int(input())
graph=[[]*i for i in range(n+1)]
visited=[False]*(n+1)
answer=0
for _ in range(m): #그래프 생성
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
def bfs(graph,visited,answer):
    que=deque()
    que.append(1)
    visited[1]=True
    while que:
        cur=que.popleft()
        if visited[cur]==False:
            visited[cur]=True
            answer+=1
        for i in graph[cur]:
            if visited[i]==False:
                que.append(i)
                visited[i]=True
                answer+=1
    return answer
print(bfs(graph,visited,answer))