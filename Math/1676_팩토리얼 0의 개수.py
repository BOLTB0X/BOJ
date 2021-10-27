#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
fac=1
cnt=0

# 팩토리얼
for i in range(1,n+1):
    fac*=i

ans=str(fac)

#역으로
for num in ans[::-1]:
    if num=='0':
        cnt+=1
    else:
        break

#출력
print(cnt)