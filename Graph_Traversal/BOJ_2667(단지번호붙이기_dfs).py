n=int(input())
apart_graph=[]
for _ in range(n):
    apart_graph.append(list(map(int,input())))
dx=[-1,1,0,0]
dy=[0,0,-1,1]
apart_num=0
visited=[[False] *n for _ in range(n)]
apart_imfo={}
def dfs(x,y):
    visited[x][y]=True
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<= nx <n and 0<= ny <n:
            if apart_graph[nx][ny]==1 and visited[nx][ny]==False:
                dfs(nx,ny)
                apart_imfo[apart_num]+=1
for i in range(n):
    for j in range(n):
        if apart_graph[i][j]!=0 and visited[i][j]==False:
            apart_imfo[apart_num]=1
            dfs(i,j)
            apart_num+=1
apart_imfo=sorted(apart_imfo.values())
print(len(apart_imfo))
for num in apart_imfo:
    print(num)