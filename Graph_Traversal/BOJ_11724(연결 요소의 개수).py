# #DFS
# n,m=map(int,input().split())
# graph=[[]*i for i in range(n+1)]
# visited=[False]*(n+1)
# answer=0
# for _ in range(m): #그래프 생성
#     a,b=map(int,input().split())
#     graph[a].append(b)
#     graph[b].append(a)
#     graph[a].sort()
#     graph[b].sort()
# def dfs(graph,visited,start):
#     visited[start]=True
#     for i in graph[start]:
#         if visited[i]==False:
#             dfs(graph,visited,i)
# for i in range(1,len(graph)):
#     if visited[i]==True:
#         continue
#     else:
#         dfs(graph,visited,i)
#         answer+=1
# print(answer)

#BFS
from collections import deque
n,m=map(int,input().split())
graph=[[]*i for i in range(n+1)]
visited=[False]*(n+1)
answer=0
result=0
for _ in range(m): #그래프 생성
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
def bfs(graph,visited,start):
    que=deque()
    que.append(start)
    #visited[start]=True 연결 노드만 확인 체크 X
    while que:
        cur=que.popleft()
        for i in graph[cur]:
            if visited[i]==False:
                que.append(i)
                visited[i]=True
for i in range(1,len(graph)):
    if visited[i]==False:
        bfs(graph,visited,i)
        answer+=1
print(answer)