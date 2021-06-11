n=int(input())
fac=1
cnt=0
for i in range(1,n+1):
    fac*=i
ans=str(fac)
for num in ans[::-1]:
    if num=='0':
        cnt+=1
    else:
        break
print(cnt)