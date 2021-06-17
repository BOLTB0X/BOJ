from collections import deque
def bfs(que, answer):
    day = answer
    while que:
        cur = que.popleft()
        day=cur[2]
        for i in range(4):
            nx = cur[0]+ dx[i]
            ny = cur[1] + dy[i]
            if (0 <= nx < n) and (0 <= ny < m):
                if graph[nx][ny] == 0 and graph[nx][ny] != -1:
                    graph[nx][ny] = 1
                    que.append([nx, ny, day + 1])
    return day

def check(answer, graph):
    for i in range(len(graph)):
        for j in range(len(graph[i])):
            if graph[i][j] == 0:
                return -1
    return answer

m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 0
que = deque([])

for i in range(len(graph)):
    for j in range(len(graph[i])):
        if graph[i][j] == 1:
            que.append([i, j, answer])
answer = bfs(que, answer)
print(check(answer, graph))