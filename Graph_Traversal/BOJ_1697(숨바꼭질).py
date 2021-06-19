from collections import deque
MAX=100001
n,k=map(int,input().split())
cnt=[0]*MAX

def bfs():
    que=deque()
    que.append(n)
    while que:
        step=que.popleft()
        if step==k:
            print(cnt[step])
            return
        for next_step in (step-1,step+1,step*2):
            if 0<=next_step <MAX and cnt[next_step]==0:
                cnt[next_step]=cnt[step]+1
                que.append(next_step)
bfs()