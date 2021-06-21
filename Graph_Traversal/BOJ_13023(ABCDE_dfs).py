n,m=map(int,input().split())
visited=[False] *(n)
graph=[[] for _ in range(n)]
def dfs(cur,dep):
    global answer
    visited[cur]=True
    if dep==4:
        answer=True
        return
    for i in graph[cur]:
        if not visited[i]:
            dfs(i,dep+1)
            visited[i]=False

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
answer=False
for i in range(n):
    dfs(i,0)
    visited[i]=False
    if answer:
        break
print(1 if answer else 0)