from collections import deque
#1: 빨강 2: 파랑 0: 미방문
def BFS(start):
    que = deque()
    que.append(start)
    visited[start]=1 #시작을 빨강 처리
    while que:
        next=que.pop()
        for i in range(len(graph[next])):
            if visited[next] == 1:
                if visited[graph[next][i]] == 0:
                    que.append(graph[next][i])
                    visited[graph[next][i]] = 2
            elif visited[next] == 2: 
                if visited[graph[next][i]] == 0:
                    que.append(graph[next][i])
                    visited[graph[next][i]] = 1
T=int((input()))
while T!=0:
    v,e=map(int,input().split())
    graph=[[] for _ in range(v+1)]
    visited=[0]*(v+1)
    for _ in range(e):
        a,b=map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    for i in range(1,v+1):
        if visited[i]==0:
            BFS(i)
    check=True;
    for i in range(1,v+1):
        for j in range(len(graph[i])):
            if visited[i]==visited[graph[i][j]]:
                check=False
    if check:
        print("YES")
    else:
        print("NO")
    T-=1