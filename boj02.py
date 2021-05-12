#1977번 완전제곱수
m=int(input())
n=int(input())

#11098번 첼시를 도와줘!
n=int(input())
for i in range(n):
    p = int(input())
    mxc=''
    mxs=0
    for j in range(p):
        s,c=map(str,input().split())
        s=int(s)
        if s>mxs:
            mxs=s
            mxc=c
    print(mxc)

# 5635번 생일
n=int(input())
lst=[]
for i in range(n):
    name,d,m,y=input().split()
    lst.append([n,int(d),int(m),int(y)])
lst=sorted(lst,key=lambda x:(x[3],x[2],x[1]))
print(lst[-1][0])
print(lst[0][0])

#1408번 24
h1,m1,s1=map(int,input().split(':'))
h2,m2,s2=map(int,input().split(':'))
if (h2-h1)<=0:
    if (h2-h1)==0:

print((h2-h1),(m2-m1),(s2-s1),sep=':')

#10984
t1=int(input())
for i in range(t1):
    t2=int(input())
    tn=tg=0
    for j in range(t2):
        n,g=map(float,input().split())
        tn+=n
        tg+=n*g
    print(int(tn),'%.1f'%(tg/float(tn)))

#9295
n=int(input())
li=[]
for i in range(1,n+1):
    a,b=map(int,input().split())
    print('Case','%d:'%i,a+b)

#9325
t=int(input())
tot=0
for i in range(t):
    s=int(input())
    tot = 0
    for j in range(int(input())):
        q,p=map(int,input().split())
        tot+=q*p
    print(s+tot)
#5522
tot=0
for i in range(5):
    n=int(input())
    tot+=n
print(tot)

#10995
n=int(input())
for i in range(1,n+1):
    if i%2==0:
        print(' *'*n)
    else:
        print('* ' * n)

#10872
n=int(input())
fac=1
for i in range(1,n+1):
    fac *=i
print(fac)

#2501
n,k=map(int,input().split())
li=[]
for i in range(1,n+1):
    if n%i==0:
        li.append(n//i)
li_set=set(li)
li_org=list(li_set)
li_org.sort()
if k>len(li_org):
    print(0)
else:
    print(li_org[k-1])

#10833
n=int(input())
rest=0
for i in range(n):
    a,b=map(int,input().split())
    rest +=b%a
print(rest)

#10178
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    ans=a//b
    rest=a%b
    print('You get',ans,'piece(s) and your dad gets',rest,'piece(s).')

#2475
a,b,c,d,e=map(int,input().split())
tot=(a**2)+(b**2)+(c**2)+(d**2)+(e**2)
print(tot%10)

#10569
t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    print(2+b-a)

#2576
li=[]
tot=0
for i in range(7):
    n=int(input())
    if n%2!=0:
        li.append(n)
        tot+=n
li.sort()
if tot==0:
    print(-1)
else:
    print(tot)
    print(li[0])

#10797
n=int(input())
cnt=0
li=list(map(int,input().split()))
for i in li:
    if i==n:
        cnt+=1
print(cnt)

# 9085
n=int(input())
for i in range(n):
    m=int(input())
    li = list(map(int, input().split()))
    tot = 0
    for j in range(m):
        tot+=li[j]
    print(tot)

#2506
n=int(input())
li = list(map(int, input().split()))
tot=cnt=0
for j in range(n):
    if li[j]==1:
        cnt+=1
        tot+=cnt
    else:
        cnt=0
print(tot)

#1546
n=int(input())
li=list(map(int,input().split()))
mxn=max(li)
for i in range(n):
    li[i]=li[i]/mxn*100
avg=sum(li)/n
print(avg)

#2455
num=0
mx=0
for i in range(4):
    a,b=map(int,input().split())
    num-=a
    num+=b
    if num>mx:
        mx=num
print(mx)

#2490
for i in range(3):
    li=list(map(int,input().split()))
    f = b = 0
    for j in range(len(li)):
        if li[j]==1:
            b+=1
        else:
            f+=1
    if f==1 and b==3:
        print('A')
    elif f==b==2:
        print('B')
    elif f==3 and b==1:
        print('C')
    elif f==4:
        print('D')
    else:
        print('E')

#2921
n=int(input())
cnt=0
for i in range(n+1):
    for j in range(i,n+1):
        cnt+=i+j
print(cnt)

#2581
m=int(input())
n=int(input())
li=[]
for i in range(m,n+1):
    if i==1:
        pass
    elif i==2:
        li.append(i)
    else:
        for j in range(2,i):
            if i%j==0:
                break
            elif j==i-1:
                li.append(i)
if len(li)==0:
    print(-1)
else:
    print(sum(li))
    print(min(li))

#1978
n=int(input())
nums=list(map(int,input().split()))
cnt=0
for num in nums:
    if num==1:
        pass
    elif num==2:
        cnt+=1
    else:
        for i in range(2,num):
            if num%i==0:
                break
            elif i==num-1:
                cnt+=1
print(cnt)

#1977
m=int(input())
n=int(input())
li=[]
for i in range(1,n):
    if m<=i*i and n>=i*i:
        li.append((i*i))
if len(li)==0:
    print(-1)
else:
    print(sum(li))
    print(min(li))

#2609
from math import gcd
def lcm(x,y):
    return x*y//gcd(x,y)
a,b=map(int,input().split())
print(gcd(a,b))
print(lcm(a,b))

#1408
h1, m1, s1 = map(int, input().split(':'))
h2, m2, s2 = map(int, input().split(':'))
t = h2*3600+m2*60+s2 - (h1*3600+m1*60+s1)
if t < 0:
    t += 60*60*24
h = t//3600
m = (t%3600)//60
s = t%60
print("%02d:%02d:%02d" % (h,m,s))

#5565
money=int(input())
for _ in range(9):
    n=int(input())
    money-=n
print(money)

#2747
def fib(n):
    a,b=0,1
    for i in range(n):
        a,b=b,a+b
    return a
print(fib(int(input())))

#5635
n=int(input())
lst=[]
for _ in range(n):
    name,d,m,y=input().split()
    if len(m)==1:
        m='0'+m
    if len(d)==1:
        d='0'+d
    lst.append((name,y+m+d))
lst.sort(key=lambda x:int(x[1]))
print(lst[n-1][0])
print(lst[0][0])

