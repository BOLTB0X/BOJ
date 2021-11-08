from collections import deque
#입력
import sys
input = lambda :sys.stdin.readline().rstrip()

#너비우선탐색
def BFS(start,target):
    que=deque()
    que.append(start)
    
    check[start]=1
    cnt=0

    while que:
        x=que.popleft()
        if x==target:
            cnt+=1

        for nx in [x *2,x+1,x-1]:
            if 0<=nx<MAX:
                if check[nx]==0 or check[nx]>=check[x]+1:
                    check[nx]=check[x]+1
                    que.append(nx)
    
    return check[target]-1,cnt

MAX=100001
n,k=map(int,input().split())
check=[0]*MAX

ans1,ans2=BFS(n,k)
print(ans1)
print(ans2)
