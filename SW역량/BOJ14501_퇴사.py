#대표적인 DP문제
n=int(input())
time,pay=[0 for i in range(n+1)],[0 for i in range(n+1)]
for i in range(n):
    #금액과 일정을 리스트에 담음
    t,p=map(int,input().split())
    time[i]=t
    pay[i]=p
dp=[0 for i in range(n+1)] #dp

for i in range(len(time)-2,-1,-1): #역순으로 진행, 문제조건상 마지막날은 안됌
    if time[i]+i <=n: #일정을 초과하지 않는 경우
        dp[i]=max(pay[i]+dp[i+time[i]],dp[i+1])
    else: #일정을 초과하는 경우
        dp[i]=dp[i+1]
print(dp[0])
