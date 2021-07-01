n=int(input())
i=1
ans=0
while i<=n:
    ans+=(n-i+1) #각 자리수 체크
    i*=10
print(ans)
