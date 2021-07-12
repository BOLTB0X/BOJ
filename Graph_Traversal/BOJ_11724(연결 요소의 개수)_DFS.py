n,m=map(int,input().split())
graph=[[] for i in range(n+1)]
visited=[False]*(n+1)
answer=0

for _ in range(m): #그래프 생성
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(graph,visited,start):
    visited[start]=True
    for i in graph[start]:
        if visited[i]==False:
            dfs(graph,visited,i)
            
for i in range(1,len(graph)):
    if visited[i]==True:
        continue
    else:
        dfs(graph,visited,i)
        answer+=1
print(answer)