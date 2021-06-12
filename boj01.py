#2588 곱셈
a=input()
b=input()
print(int(a)*int(b[2]))
print(int(a)*int(b[1]))
print(int(a)*int(b[0]))
print(int(a)*int(b))

#3046 R2
r1,s=map(int,input().split())
print((s*2)-r1)

#2163 초콜릿 자르기
n,m=map(int,input().split())
print((n*m)-1)

#11021 A+B-7
n=int(input())
li=[]
for i in range(n):
    a,b=map(int,input().split())
    li.append(a+b)
for i in range(n):
    print('Case #%i'%(i+1)+':',li[i])

#11022 A+B-8
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    print('Case #%s: %s + %s = %s'%(i+1,a,b,a+b))

# 10699 오늘 날짜
from datetime import datetime
print(datetime.today().strftime("%Y-%m-%d"))
 
# 7287 등록
print('42')
print('khunlee0508')

# 2525번 오븐시계
a,b=map(int,input().split())
c=int(input())
if (b+c)>=60:
    a+=(b+c)//60 
    if a>23:
        a-=24
    b=(b+c)%60
    print(a,b)
else:
    print(a,b+c)
##다른 풀이
a+=c//60
b+=c%60
if b>=60:
    a+=1
    b-=60
if a>=24:
    a-=24
print(a,b)

# 2530 인공지능 시계
a,b,c=map(int,input().split())
d=int(input())
c+=d%60
b+=d//60
while a>=24 or b>=60 or c>=60:
    if c>=60:
        b+=1
        c-=60
    if b>=60:
        a+=1
        b-=60
    if a>=24:
        a-=24
print(a,b,c)

#2914 저작권
a,i=map(int,input().split())
print((a*(i-1)+1))

#5355 화성수학
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

#2675번 문자열 반복
t=int(input())
for _ in range(t):
    r,s=map(str,input().split())
    p=''
    for i in range(len(s)):
        p=p+(int(r)*s[i])
    print(p)

#2935번 소음
a=int(input())
c=input()
b=int(input())
if c=='*':
    print(a*b)
else:
    print(a+b)

10039번 평균 점수
tot=0
for _ in range(5):
    a=int(input())
    if a<=40:
        a=40
    tot+=a
print(tot//5)

#10817번 세수
a,b,c=map(int,input().split())
fir=sec=a
if fir <=b:
    fir=b
    if fir<=c:
        fir=c
        sec=b
    else:
        sec=max(a,c)
else:
    if fir<=c:
        fir=c
        sec=a
    else:
        sec=max(b,c)
print(sec)

a,b,c=map(int,input().split())

if a>=b:
    if a>=c:
        if b>=c:
            print(b)
        else:
            print(c)
    else:
        print(a)
else:
    if b>=c:
        if a>=c:
            print(a)
        else:
            print(c)
    else:
        print(b)

#1934 최소공배수
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    for i in range(b,(a*b)+1):
        if i%a==0 and i%b==0:
            print(i)
            break
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    i=b
    while True:
        if i%a==0 and i%b==0:
            print(i)
            break
        i+=1
for i in range(int(input())):
    a,b=map(int,input().split())
    x=a
    y=b
    while b !=0:
        r=a%b
        a=b
        b=r
    lcd=x*y/a
    print(int(lcd))

#11753번
n=int(input())
i=2;
while n!=1:
    if n%i==0:
        n/=i
        print(i)
    else:
        i+=1
# 2480 주사위 세개
a,b,c=map(int,input().split())
if a==b:
    if b==c:
        print(10000+(a*1000))
    else:
        print(1000 + (a * 100))
elif a!=b:
    if b==c:
        print(1000 + (b * 100))
    else:
        print(max(a,b,c) * 100)
elif a==c:
    if c==b:
        print(10000+(a*1000))
    else:
        print(1000 + (a * 100))
elif a!=c:
    if c==b:
        print(1000 + (c * 100))
    else:
        print(max(a,b,c) * 100)
elif b == c:
    if a == c:
        print(10000 + (a * 1000))
    else:
        print(1000 + (b * 100))
elif b != c:
    if a == c:
        print(1000 + (a * 100))
    else:
        print(max(a,b,c) * 100)

#4101번 크냐?
while True:
    a,b=map(int,input().split())
    if a>b:
        print('Yes')
    elif a==b==0:
        break
    else:
        print('No')

#10156번 과자
a,b,c=map(int,input().split())
if (a*b)>=c:
    print((a*b)-c)
else:
    print(0)

#3009번 네 번째 점
x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
x3,y3=map(int,input().split())

#2476번 주사위 게임
n=int(input())
d=[]
for i in range(n):
    a,b,c=map(int,input().split())
    if a==b:
        if b==c:
            d.append(10000+(a*1000))
        else:
            d.append(1000 + (a * 100))
    elif a!=b:
        if b==c:
            d.append(1000 + (b * 100))
        else:
            d.append(max(a,b,c) * 100)
    elif a==c:
        if c==b:
            d.append(10000+(a*1000))
        else:
            d.append(1000 + (a * 100))
    elif a!=c:
        if c==b:
            d.append(1000 + (c * 100))
        else:
            d.append(max(a,b,c) * 100)
    elif b == c:
        if a == c:
            d.append(10000 + (a * 1000))
        else:
            d.append(1000 + (a * 100))
    elif b != c:
        if a == c:
            d.append(1000 + (a * 100))
        else:
            d.append(max(a,b,c) * 100)
max=0
max=int(d[0])
for i in range(len(d)):
    if max<int(d[i]):
        max=int(d[i])
print(max)

#2754번 학점계산
g=input()
if g=='A+':
    print(4.3)
elif g=='A0':
    print(4.0)
elif g=='A-':
    print(3.7)
elif g=='B+':
    print(3.3)
elif g=='B0':
    print(3.0)
elif g=='B-':
    print(2.7)
elif g=='C+':
    print(2.3)
elif g=='C0':
    print(2.0)
elif g=='C-':
    print(1.7)
elif g=='D+':
    print(1.3)
elif g=='D0':
    print(1.0)
elif g=='D-':
    print(0.7)
else:
    print(0.0)

#7567번 그릇
n=input()
ans=10
for i in range(1,len(n)):
    if n[i-1]==n[i]:
        ans+=5
    else:
        ans+=10
print(ans)

#5063번 TGN
n=int(input())
for i in range(n):
    r,e,c=map(int,input().split())
    if e>(r+c):
        print('advertise')
    elif e==(r+c):
        print('does not matter')
    else:
        print('do not advertise')

#10102번
n=int(input())
li=list(input())
a=0
b=0
for i in range(n):
    if li[i]=='A':
        a+=1
    else:
        b+=1
if a>b:
    print('A')
elif a<b:
    print('B')
else:
    print('Tie')

#10886번 0=not cute /1=cute
n=int(input())
like=0
dislike=0
for i in range(n):
    v=int(input())
    if v!=0:
        like+=1
    else:
        dislike+=1
if like>dislike:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")

#10988번 팰린드롬인지 확인하기
a=input()
b=a[::-1]

if a==b:
    print(1)
else:
    print(0)

#5086번 배수와 약수
while True:
    a,b=map(int,input().split())
    if a==0 and b==0:
        break
    elif b%a==0:
        print('factor')
    elif a%b==0:
        print('multiple')
    else:
        print('neither')

#5717번 상근이의 친구들
while True:
    a,b=map(int,input().split())
    if a == 0 and b == 0:
        break
    print(a+b)

#9610번 사분면
n=int(input())
q1=q2=q3=q4=axis=0
for i in range(n):
    a,b=map(int,input().split())
    if a==0 or b==0:
        axis+=1
    elif a>0 and b>0:
        q1+=1
    elif a>0 and b<0:
        q4+=1
    elif a<0 and b>0:
        q2+=1
    elif a<0 and b<0:
        q3+=1
print('Q1:',q1)
print('Q2:',q2)
print('Q3:',q3)
print('Q4:',q4)
print('AXIS:',axis)

#8958번 OX퀴즈
n=int(input())
for i in range(n):
    a=input()
    o = 1
    cnt = 1
    for j in range(1,len(a)):
        if a[j-1]==a[j]=='O':
            cnt+=1
            o+=cnt
        elif a[j-1]!=a[j]:
            cnt = 1
            o += cnt
    print(o)

#10162번 전자레인지
t=int(input())
a=b=c=0
while t!=0:
    if t>=300:
        t-=300
        a+=1
    elif t>=60:
        t-=60
        b+=1
    elif t>=10:
        t-=10
        c+=1
    elif t%10!=0:
        break
if t!=0:
    print(-1)
else:
    print(a,b,c)
    
#10103번 주사위 게임
n=int(input())
x=y=100
for i in range(n):
    a,b=map(int,input().split())
    if a>b:
        y-=a
    elif a<b:
        x-=b
print(x)
print(y)

#10214번 baseball
n=int(input())
for i in range(n):
    yv = kv = 0
    for j in range(9):
        y,k=map(int,input().split())
        yv+=y
        kv+=k
    if yv>kv:
        print('Yonsei')
    elif yv>kv:
        print('Korea')
    else:
        print('Draw')

#11557번 Yangjojang of The Year
t=int(input())
for i in range(t):
    n = int(input())
    mxs=''
    mxl=0
    for j in range(n):
        s,l=list(map(str,input().split()))
        l=int(l)
        if l>mxl:
            mxl=l
            mxs=s
    print(mxs)

#10757번 큰 수 A+B
a,b=map(int,input().split())
print(a+b)

#2480
a,b,c=map(int,input().split())
ans=0
if a==b==c:
    print(10000+a*1000)
elif a==b!=c:
    print(1000+a*100)
elif a!=b==c:
    print(1000+b*100)
elif a==b!=c:
    print(1000+a*100)
elif a==c!=b:
    print(1000+a*100)

else:
    print(max(a,b,c)*100)

#8958
for _ in range(int(input())):
    s=input()
    a=list(s)
    check = 0
    tot=0
    for ch in a:
        if ch=='O':
            check+=1
        elif ch=='X':
            for i in range(1,check+1):
                tot+=i
            check=0
    for j in range(1,check+1):
        tot+=j
    print(tot)

#9506
while True:
    n=int(input())
    nums=[]
    if n==-1:
        break
    for i in range(1,n):
        if n%i==0:
            nums.append(i)
    if sum(nums)==n:
        print(sum(nums),end=' = ')
        for j in range(len(nums)):
            print(nums[j],end=' ')
            if j<len(nums)-1:
                print('+',end=' ')
    else:
        print(n,'is NOT perfect.')

#1789 수들의 합
n= int(input()) 
cnt=0
sum=0
while True: #수열의 공식 (n(n+1))/2 이용
    cnt+=1 
    sample1=(cnt*(cnt+1))/2
    sample2=((cnt+1)*(cnt+2))/2
    if sample1<=n and sample2>n:  #최대값은 이 범위에 해당
        break  
print(i) 

#2476 주사위 게임
money=[]
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a==b==c:
      money.append(10000+(a*1000))
    elif a==b!=c:
       money.append(1000+(a*100))
    elif a!=b==c:
        money.append(1000+(b*100))
    elif a==c!=b:
        money.append(1000+(a*100))
    else:
        money.append(max(a,b,c)*100)
print(max(money))

#3009 네번째 집
x_=[]
y_=[]
for i in range(3):
    x,y=map(int,input().split())
    x_.append(x)
    y_.append(y)
for i in range(3):
    if x_.count(x_[i])==1:
        x4=x_[i]
    if y_.count(y_[i])==1:
        y4=y_[i]
print(x4,y4)
