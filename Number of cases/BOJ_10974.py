#모든순열
from itertools import permutations
n=int(input())
p=list(permutations([i for i in range(1,n+1)], n))
for i in range(len(p)):
    for j in p[i]:
        print(j,end=' ')
    print()
