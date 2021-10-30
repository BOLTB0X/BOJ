from itertools import combinations_with_replacement as com
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())

c=list(com(range(1,n+1),m))
for i in c:
    print(*i)