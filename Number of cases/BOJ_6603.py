#로또
from itertools import combinations
import sys
input = lambda :sys.stdin.readline().rstrip()
while True:
    k,*s=map(int,input().split())
    if k==0:
        break
    C=list(combinations(s,6))

    for i in C:
        print(*i)
    print()
