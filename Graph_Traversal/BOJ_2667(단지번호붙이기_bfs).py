from collections import deque
n=int(input())
apart_graph=[]
for _ in range(n):
    apart_graph.append(list(map(int,input())))
dx=[-1,1,0,0]
dy=[0,0,-1,1]
apart_num=0
visited=[[False] *n for _ in range(n)]
apart_imfo={}
def bfs(x,y):
    que=deque([[x,y]])
    visited[x][y]=True
    while que:
        move=que.popleft()
        for i in range(4):
            nx=move[0]+dx[i]
            ny=move[1]+dy[i]
            if 0<=nx<n and 0<=ny<n:
                if apart_graph[nx][ny]==1 and visited[nx][ny]==False: #아파트이고 방문하지 않았다면
                    que.append([nx,ny])
                    visited[nx][ny]=True
                    apart_imfo[apart_num]+=1
for i in range(n):
    for j in range(n):
        if apart_graph[i][j]!=0 and visited[i][j]==False:
            apart_imfo[apart_num]=1
            bfs(i,j)
            apart_num+=1
apart_imfo=sorted(apart_imfo.values())
print(len(apart_imfo))
for num in apart_imfo:
    print(num)