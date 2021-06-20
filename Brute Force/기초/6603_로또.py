from itertools import combinations
while True:
    n,*com=map(int,input().split())
    if n==0:
        break
    C=list(combinations(com,6))
    for c in C:
        print(*c)