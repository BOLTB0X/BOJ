#중복허용하지 않는 순열
from itertools import product
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())

pro=list(product([i for i in range(1,n+1)],repeat=m))

for p in pro:
    print(*p)