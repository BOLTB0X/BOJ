
n=int(input())

for _ in range(n):
    ans=[]
    a,b=input().split()
    for i in range(len(a)):
        trans_a=int(ord(a[i])-ord('A')+1)
        trans_b=int(ord(b[i])-ord('A')+1)
        if trans_b>=trans_a:
            ans.append(trans_b-trans_a)
        else:
            ans.append((trans_b+26)-trans_a)
    print("Distances:",*ans)