from collections import deque
n = int(input())
aparts_graph=[]
for _ in range(n): #그래프 생성
    aparts_graph.append(list(map(int,input())))
visited=[[False]*n for _ in range(n)] #방문 리스트
dx=[-1,1,0,0]
dy=[0,0,-1,1]
aparts_num={} #단지 번호와 갯수를 담는 딕셔너리
num=0
def bfs(x, y, num):
    que=deque([[x,y]]) #x,y를 리스트로 뽑는다
    visited[x][y]=True #방문처리
    while que:
        m= que.popleft()
        for i in range(4): #각 이동방향 
            nx=m[0]+dx[i]
            ny=m[1]+dy[i]
            if 0<= nx < n and 0<= ny < n: #범위 안에 들면
                if aparts_graph[nx][ny]==1 and visited[nx][ny]==False: #아파트이고 방문하지 않았다면
                    que.append([nx,ny])
                    visited[nx][ny]=True
                    aparts_num[num]+=1 #넣어라
for i in range(n):
    for j in range(n):
        if aparts_graph[i][j]!=0 and visited[i][j]==0:
            aparts_num[num]=1
            bfs(i,j,num)
            num+=1 #탐색 후 아파트 단지 넘버 +1증가
aparts_num=sorted(aparts_num.values())
print(len(aparts_num))
for num in aparts_num:
    print(num)