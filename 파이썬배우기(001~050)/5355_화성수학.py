#화성수학 https://www.acmicpc.net/problem/5355
n=int(input())
for i in range(n):
    a=list(map(str,input().split()))
    ans=0
    for j in range(len(a)):
        if j==0:
            ans+=float(a[j])
        else:
            if a[j]=='@':
                ans*=3
            if a[j]== '%':
                ans+=5
            if a[j]=='#':
                ans-=7
    print("%.2f"%ans)