from collections import deque
#입력
import sys
input = lambda :sys.stdin.readline().rstrip()

#너비우선탐색
def BFS(n, visited): 
    que = deque() 
    que.append(n) 
    visited[n] = True
    
    #큐가 비어질때까지
    while que: 
        x = que.popleft() 
        
        #탈출 조건
        if x == k: 
            return sec[x]
        
        #각 케이스 반복
        for nx in (x*2, x-1, x+1): 
            #범위내이고 미방문인 경우
            if 0 <= nx <= 100000 and not visited[nx]:
                #순간이동
                if nx == x*2: 
                    sec[nx] = sec[x]
                
                #그 외
                else: 
                    sec[nx] = sec[x] + 1 
                
                #위치 삽입
                que.append(nx) 
                visited[nx] = True 

n, k = map(int, input().split()) 
sec = [0] * 100001 
visited = [False] * 100001 

#출력
print(BFS(n, visited))
