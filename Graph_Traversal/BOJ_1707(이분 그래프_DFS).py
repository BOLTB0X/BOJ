import sys
sys.setrecursionlimit(100000)
def dfs(start,color):
    visited[start] = color
    for i in graph[start]:
        if visited[i] == 0: #미방문
            if not dfs(i,-color):
                return False
        elif visited[i] == visited[start]: #방문한 곳이 같은 색깔이면
            return False
    return True
T=int((input()))
while T!=0:
    v,e=map(int,input().split())
    graph=[[] for _ in range(v+1)]
    visited=[0]*(v+1)
    for _ in range(e):
        a,b=map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
    check=True
    for i in range(1, v+1):
        if visited[i] == 0: # 방문한 정점이 아니면, dfs 수행
            check = dfs(i, 1)
            if not check:
                break
    print('YES' if check else 'NO')
    T-=1