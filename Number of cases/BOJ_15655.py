from itertools import combinations
import sys
input=lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
C=combinations(arr,m)
for i in C:
    print(*i)