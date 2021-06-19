#시간 초과
from itertools import permutations
n=int(input())
P=list(map(int,input().split()))
per=permutations(P,n)
cnt=0
def checkSame(p,P):
    check=0
    for i in range(len(p)):
        if p[i]==P[i]:
            continue
        else:
            check+=1
    return check

for p in per:
    if checkSame(list(p),P)==0:
        if cnt==0:
            print(-1)
        else:
            print(per[cnt-1])
    else:
        cnt+=1

#정답코드 
n = int(input())
p = list(map(int, input().split()))

def prev_permutation(a): #이전순열 알고리즘
    i = len(a)-1 
    while i > 0 and a[i-1] <= a[i]: 
        i -= 1 
    if i <= 0: 
        return False 
    j = len(a)-1 
    while a[j]>= a[i-1]: 
        j -= 1 
    a[i-1],a[j] = a[j],a[i-1] 
    j = len(a)-1 
    while i<j: 
        a[i],a[j] = a[j],a[i] 
        i += 1 
        j -= 1 
    return True


if prev_permutation(p):
    print(*p)
else:
    print(-1)