#입출력
from sys import stdin
#입력 
input = stdin.readline

#깊이우선탐색
def DFS(start,dep):
    global answer
    visited[start]=True
    if dep==4:
        answer=True
        return
    for i in graph[start]:
        if not visited[i]:
            DFS(i,dep+1)
            visited[i]=False

n,m=map(int,input().split())
graph=[[] for _ in range(n)]
visited=[False]*n

#무향그래프 생성
for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

answer=False

#각 노드 탐색
for i in range(len(graph)):
    DFS(i,0)
    visited[i]=False
    if answer:
        break

#출력
print(1 if answer else 0)