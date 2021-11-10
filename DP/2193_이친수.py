#입력
import sys
input = sys.stdin.readline

n=int(input())

#dp테이블 초기화
dp=[0, 1, 1]

#보텀업
for i in range(3,n+1):
    dp.append(dp[i-2] + dp[i-1])

#출력
print(dp[n])