n=int(input())
arr=list(map(int,input().split()))
mai,sub=map(int,input().split())

cnt=0

for i in range(n):
    arr[i]-=mai
    cnt+=1

    if arr[i] > 0:
        if (arr[i]%sub)==0:
            cnt+=int(arr[i]//sub)
        else:
            cnt+=int(arr[i]//sub)+1

print(cnt)
