from itertools import product
import sys
input = lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
P=list(product([i for i in range(1,n+1)],repeat=m))
for i in P:
    print(*i)