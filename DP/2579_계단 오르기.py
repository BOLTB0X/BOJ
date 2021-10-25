#입력
n=int(input())
steps=[]

for i in range(n):
    height=int(input())
    steps.append(height)

#dp테이블
dp=[0 for _ in range(n)]

#메모이제이션
dp[0] = steps[0]
dp[1] = steps[0]+steps[1]
dp[2] = max(steps[1]+steps[2],steps[0]+steps[2])

#보텀업
for i in range(3,n):
    dp[i] = max(steps[i-1]+steps[i]+dp[i-3],steps[i]+dp[i-2])

#출력
print(dp[n-1])