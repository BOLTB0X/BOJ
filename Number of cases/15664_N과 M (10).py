from itertools import combinations
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
arr=sorted(list(map(int,input().split())))
C=sorted(set(combinations(arr,m)))

#출력
for c in C:
    print(*c)