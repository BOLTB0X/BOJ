def gcd(a,b): #최대공약수
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

for _ in range(int(input())):
    arr=list(map(int,input().split()))
    k=arr.pop(0)
    tot=0
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            tot+=gcd(arr[i],arr[j])
    print(tot)
