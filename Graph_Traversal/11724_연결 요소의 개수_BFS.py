#BFS
from collections import deque
#입출력
from sys import stdin
#입력 
input = stdin.readline

#너비 우선 탐색
def BFS(graph,visited,v):
    que=deque()
    que.append(v)
    while que:
        x=que.popleft()
        
        for i in graph[x]:
            if visited[i]==False:
                que.append(i)
                visited[i]=True

n,m=map(int,input().split())
#그래프 및 방문리스트 생성 및 초기화
graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)
answer=0

for _ in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,len(graph)):
    #재방문
    if visited[i]== True:
        continue
    #호출
    BFS(graph,visited,i)
    answer+=1

#출력
print(answer)