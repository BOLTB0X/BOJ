import sys
input = sys.stdin.readline

dp = [0] * 41
dp[1] = 1

def fibonacci(n):
    for i in range(2,n+1):
        dp[i]=dp[i-1]+dp[i-2]
        
#입력        
T=int(input())

for _ in range(T):
    n = int(input())
    
    if n == 0:
        print("1 0")
    else:
        fibonacci(n)
        print("%d %d"%(dp[n-1],dp[n]))