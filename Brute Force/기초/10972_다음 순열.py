from itertools import permutations
#메모리 초과
n=int(input())
p_list=[i for i in range(1,n+1)]
target_p=list(map(int,input().split()))
all_p=list(permutations(p_list,n))
cnt=0
for P in all_p:
    if list(P)==target_p:
        if cnt==len(all_p)-1:
            print(-1)
        else:
            print(*all_p[cnt+1])
    cnt+=1

n=int(input())
target_p=list(map(int,input().split()))
def next_permutation(a): 
    i = len(a)-1 
    while i > 0 and a[i-1] >= a[i]: 
        i -= 1 
    if i <= 0: 
        return False 
    j = len(a)-1 
    while a[j] <= a[i-1]: 
        j -= 1 
    a[i-1],a[j] = a[j],a[i-1]

    j = len(a)-1 
    while i < j: 
        a[i],a[j] = a[j],a[i] 
        i += 1 
        j -= 1 
    return True
if next_permutation(target_p): 
    print(*target_p)
else: 
    print(-1)