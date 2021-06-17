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

def next_permutation(p): #이전순열 알고리즘
    n=len(p)-1
    i = n
    while i>0 and p[i-1]<=p[i]:
        i-=1
    if i==0:
        return False
    j=n
    while p[i-1]<=p[j]:
        j-=1
    p[i-1],p[j]=p[j],p[i-1]
    j=n
    while i<j:
        p[i],p[j]=p[j],p[i]
        i+=1
        j-=1
    return True

if next_permutation(p)== True:
    for i in p:
        print(i, end=' ')
    print()
else:
    print(-1)