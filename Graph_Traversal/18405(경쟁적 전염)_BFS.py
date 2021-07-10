from collections import deque
def BFS(t,n):
    while que:
        virus,sec,x,y=que.popleft()
        if t==sec:
            break
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<n:
                if graph[nx][ny]==0:
                    graph[nx][ny]=virus
                    que.append((virus,sec+1,nx,ny))
                    
n,m=map(int,input().split())
graph=[]
data=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
for i in range(n):
    graph.append(list(map(int,input().split())))
    for j in range(n):
        if graph[i][j]!=0:
            data.append((graph[i][j],0,i,j))
data.sort()
que=deque(data)

t,r,c=map(int,input().split())
BFS(t,n)
print(graph[r-1][c-1])