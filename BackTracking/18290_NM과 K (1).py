#입출력
from sys import stdin
#입력 
input = stdin.readline

#결과값
result = -10000

#동서남북
dy = [-1,0,1,0]
dx = [0,1,0,-1]

#깊이우선탐색
def DFS(board, visited, n, m, k, depth, tot):
    #사용할 전역변수
    global result
    
    #탈출 조건
    if depth == k:
        result = max(result,tot)
        return
    
    #그래프 탐색
    for y in range(n):
        for x in range(m):
            #재방문인경우
            if visited[y][x]:
                continue
            
            #체크용
            flag = True
            
            #4방향 계속 탐색
            for dir in range(4):
                ny = y + dy[dir]
                nx = x + dx[dir]
                
                #범위 내
                if 0 <= ny <n and 0 <= nx <m:
                    if visited[ny][nx]:
                        flag = False
            
            #진행가능하면
            if flag:
                visited[y][x]=True
                #호출
                DFS(board, visited, n, m, k, depth + 1, tot + board[y][x])
                visited[y][x]=False


#입력
n,m,k=map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

#백트래킹 시작
DFS(board,visited,n,m,k,0,0)

#출력
print(result)