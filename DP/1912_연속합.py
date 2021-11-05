#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())

#dp테이블
dp=[0 for _ in range(n)]
#배열 입력
arr = list(map(int,input().split()))

#최댓값 셋팅
max_value=arr[0]
#dp테이블 셋팅
dp[0]=arr[0]

#보턴 업
for i in range(1,n):
    dp[i] = max(arr[i],arr[i]+dp[i-1])

    if dp[i] > max_value:
        max_value=dp[i]

print(max_value)