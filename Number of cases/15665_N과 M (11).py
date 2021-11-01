from itertools import product
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
nums=sorted(list(map(int,input().split())))

#중복제거
P=sorted(set(product(nums,repeat=m)))

#출력
for p in P:
    print(*p)