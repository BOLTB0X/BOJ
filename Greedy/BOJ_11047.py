n,k=map(int,input().split())
coin_type=[]
min_cnt=0
for i in range(n):
    coin_type.append(int(input()))
coin_type.sort(reverse=True)
for i in range(n):
    if k==0:
        break
    if k//coin_type[i]>0:
        min_cnt+=k//coin_type[i]
        k%=coin_type[i]
print(min_cnt)