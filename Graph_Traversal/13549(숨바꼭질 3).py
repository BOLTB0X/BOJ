from collections import deque 
def bfs(n, visited): 
    que = deque() 
    que.append(n) 
    visited[n] = True 
    while que: 
        x = que.popleft() 
        if x == k: 
            return sec[x] 
        for nx in (x*2, x-1, x+1): 
            if 0 <= nx <= 100000 and not visited[nx]: 
                if nx == x*2: 
                    sec[nx] = sec[x] 
                else: 
                    sec[nx] = sec[x] + 1 
                que.append(nx) 
                visited[nx] = True 
n, k = map(int, input().split()) 
sec = [0] * 100001 
visited = [False] * 100001 
print(bfs(n, visited))