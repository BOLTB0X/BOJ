n=int(input())
cnt=0
for i in range(1,n+1):
    cnt+=len(str(i)) #길이 카운트
print(cnt)
