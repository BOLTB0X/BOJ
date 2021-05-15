from itertools import product
import sys
input = lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
nums=list(map(int,input().split()))
nums.sort()
C=list(product(nums,repeat=m))
for i in C:
    print(*i)