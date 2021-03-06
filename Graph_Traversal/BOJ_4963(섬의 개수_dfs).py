def dfs(x,y):
    visited[x][y]=True
    for i in range(8):  
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<h and 0<=ny<w:
            if visited[nx][ny]==False and graph[nx][ny]==1:
                visited[nx][ny]=True
                dfs(nx,ny)  
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
while True:
    w,h=map(int,input().split())
    if w==0 and h==0:
        exit()
    graph=[]
    visited=[[False]*w for _ in range(h)]
    for _ in range(h):
        graph.append(list(map(int,input().split())))
    answer=0
    for i in range(h):
        for j in range(w):
            if graph[i][j]==1 and visited[i][j]==False:
                dfs(i,j)
                answer+=1
    print(answer)