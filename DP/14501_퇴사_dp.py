n=int(input())
time=[]
pay=[]
dp=[]
for i in range(n):
    a,b=map(int,input().split())
    time.append(a)
    pay.append(b)
    dp.append(b)
dp.append(0)

for i in range(n-1, -1, -1):
    if time[i] + i > n: #데드라인이 기한을 넘어가는경우
        dp[i] = dp[i+1]
    else:
        dp[i] = max(dp[i+1], pay[i]+dp[i+time[i]])
print(dp[0])