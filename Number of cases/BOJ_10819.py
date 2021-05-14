from itertools import permutations
import sys
input = lambda :sys.stdin.readline().rstrip()
n=int(input())
arr=list(map(int,input().split()))
P=list(permutations(arr))
ans=0
for i in P:
    tot=0
    for j in range(n-1):
        tot+=abs(i[j]-i[j+1])
    ans=max(ans,tot)
print(ans)