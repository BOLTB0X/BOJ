from itertools import combinations
import sys
input = lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
C=list(combinations(range(1,n+1),m))
print(C)
for i in C:
    print(i)