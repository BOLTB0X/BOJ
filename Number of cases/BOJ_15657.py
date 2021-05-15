from itertools import combinations_with_replacement as com
import sys
input=lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
C=com(arr,m)
for i in C:
    print(*i)