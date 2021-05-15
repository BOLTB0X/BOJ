#N과 M(1)
from itertools import permutations
import sys
input=lambda : sys.stdin.readline().rstrip()
n,m=map(int,input().split())
P=list(permutations([i for i in range(1,n+1)],m))
for i in P:
    print(*i)
