from collections import deque 
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m = map(int,input().split())
board = [list(map(int,input().rstrip())) for _ in range(n)]
#거리정보도 담기 위해 int로
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]

#상하좌우
dy = [1,-1,0,0]
dx = [0,0,-1,1]

def BFS():
    # (0, 0) 출발, 벽 안부순 상태 시작
    q = deque([(0, 0, 0)])
    visited[0][0][0] = 1

    while q:
        y, x, wall = q.popleft()
        if y == n - 1 and x == m - 1:
            return visited[y][x][wall]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            # 맵 범위 안에 있고, 한 번도 방문하지 않았으면
            if 0 <= ny < n and 0 <= nx < m and visited[ny][nx][wall] == 0:
                # 벽이 아니라면 이동하고, 이전경로 + 1 visited 배열에 저장
                if board[ny][nx] == 0:
                    q.append((ny, nx, wall))
                    visited[ny][nx][wall] = visited[y][x][wall] + 1
                
                # 벽 1번도 안 부쉈고, 다음 이동할 곳이 벽이라면
                if wall == 0 and board[ny][nx] == 1:
                    # 벽을 부순 상태를 1로 표현
                    q.append((ny, nx, 1))
                    # 벽 부순 상태의 visited[nr][nc][1]에 이전경로 + 1 저장
                    visited[ny][nx][1] = visited[y][x][wall] + 1

    return -1

print(BFS())