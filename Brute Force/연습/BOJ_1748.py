#1748 수 이어 쓰기 1
n=int(input())
cnt=0
for i in range(1,n+1):
    cnt+=len(str(i))
print(cnt)