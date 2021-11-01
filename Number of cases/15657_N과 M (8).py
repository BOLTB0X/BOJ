from itertools import combinations_with_replacement as com
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
arr=list(map(int,input().split()))

#정렬
arr.sort()
C=com(arr,m)

for c in C:
    print(*c)