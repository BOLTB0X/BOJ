#수들의 합 https://www.acmicpc.net/problem/1789
n=int(input())
tot=0
answer=0
for i in range(1,n+1):
    tot+=i
    answer=i #최댓값
    if tot>n:
        tot-=i
        answer-=1
        break
    elif tot==n:
        break
print(answer)