#입출력
from sys import stdin
#입력 
input = stdin.readline

#깊이 우선 탐색
def DFS(graph,visited,start):
    visited[start]=True
    for i in graph[start]:
        if visited[i]==False:
            DFS(graph,visited,i)

n,m=map(int,input().split())
#그래프 및 방문리스트 생성 및 초기화
graph=[[] for i in range(n+1)]
visited=[False]*(n+1)
answer=0

#그래프 생성
for _ in range(m): 
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()

for i in range(1,len(graph)):
    #재방문인 경우
    if visited[i]==True:
        continue
    #호출
    DFS(graph,visited,i)
    answer+=1

#출력
print(answer)