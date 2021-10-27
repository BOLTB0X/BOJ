#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
fac=1

#연산
for i in range(1,n+1):
    fac *=i

#출력
print(fac)