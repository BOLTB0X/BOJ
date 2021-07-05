from collections import deque
n, k = map(int, input().split())
MAX = 100001

def bfs(n,k):
    que = deque()
    que.append(n)

    cnt=0
    check=[-1]* MAX
    check[n]=0
    while que:
        x = que.popleft()
        if x==k:
            cnt+=1
        for nx in [x * 2, x + 1, x - 1]:
            if 0 <= nx < MAX:
                if check[nx]==-1 or check[nx]>=check[x]+1: #시간: 방문한 적 없거나 현재시간 +1인경우
                    check[nx]=check[x]+1
                    que.append(nx)
    return check[k],cnt
ans1,ans2=bfs(n,k)
print(ans1)
print(ans2)