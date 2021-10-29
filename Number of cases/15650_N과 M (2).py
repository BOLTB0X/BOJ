#입출력
from sys import stdin
#입력 
input = stdin.readline
#조합
from itertools import combinations

n,m=map(int,input().split())

com = list(combinations([i for i in range(1,n+1)],m))

for c in com:
    print(*c)