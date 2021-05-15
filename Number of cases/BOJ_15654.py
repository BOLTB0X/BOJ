#n과m(5)
from itertools import permutations
import sys
input=lambda : sys.stdin.readline().rstrip()
n,m=map(int,input().split())
nums=list(map(int,input().split()))
nums.sort()
P=list(permutations(nums,m))
for i in P:
    print(*i)
