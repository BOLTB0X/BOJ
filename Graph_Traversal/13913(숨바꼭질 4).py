from collections import deque
MAX=100001

def path(x):
    p= [] #다녀온 노드를 담는 리스트
    tmp=x
    for _ in range(check[x]+1):
        p.append(tmp)
        tmp=move[tmp] #x의 이전 노드로 저장 그 다음 이전노드의 이전노드가 저장 ....
    
    print(' '.join(map(str, p[::-1]))) #역순으로 저장되니

def bfs(n,k):
    que = deque()
    que.append(n)

    while que:
        x=que.popleft()
        if x==k:
            print(check[x])
            path(x)
            break
        for nx in [x-1,x+1,x*2]:
            if 0<=nx<MAX and check[nx]==0:
                que.append(nx)
                check[nx]=check[x]+1 #걸린 시간 저장
                move[nx]=x #이전 노드 저장

n, k = map(int, input().split())
check = [0]*MAX #걸리는 시간을 담는 리스트
move = [0]*MAX #이전 거쳐온 노드를 담는 리스트
bfs(n,k)
