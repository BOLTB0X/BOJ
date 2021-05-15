#N과M (4)
from itertools import combinations_with_replacement as com
import sys
input=lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
C=list(com(range(1,n+1),m))
for i in C:
    print(*i)
