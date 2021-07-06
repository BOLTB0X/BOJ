from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    que.append([x, y])
    visited[x][y] = 1

    while que: #큐가 빌떄까지
        qlen = len(que) #길이를 반환 큐가 차있어도 물이 차면 이동 X
        while qlen: # 물이 차기 전 이동
            x, y = que.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    if graph[nx][ny] == '.' and visited[nx][ny] == 0:
                        visited[nx][ny] = visited[x][y] + 1 #이동할 좌표에 걸린시간 저장
                        que.append([nx, ny])
                    elif graph[nx][ny] == 'D': #도착한다면
                        return visited[x][y]
            qlen -= 1
        water() #물이 차오름
    return "KAKTUS"

def water(): #물 차오르는 메소드
    qlen = len(wque) #큐 길이로 
    while qlen:
        x, y = wque.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == '.':
                    graph[nx][ny] = '*'
                    wque.append([nx, ny])
        qlen -= 1

n, m = map(int, input().split())
graph=[]
print(graph)
for i in range(n):
    tmp=list(input())
    graph.append(tmp)
visited = [[0]*m for _ in range(n)] #방문 리스트
que, wque = deque(), deque()

for i in range(n):
    for j in range(m):
        if graph[i][j] == 'S':
            x, y = i, j
        elif graph[i][j] == '*':
            wque.append([i, j])
water()
print(bfs(x, y))