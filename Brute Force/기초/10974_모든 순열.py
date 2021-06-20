from itertools import permutations
n=int(input())
temp=[i for i in range(1,n+1)]
per=list(permutations(temp,n))
for p in per:
    print(*p)