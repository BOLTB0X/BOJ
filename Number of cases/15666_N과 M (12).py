from itertools import combinations_with_replacement as com
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
nums=sorted(list(map(int,input().split())))

#중복 제거
C=sorted(set(com(nums,m)))

#출력
for c in C:
    print(*c)