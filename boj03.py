#2908
a,b=map(str,input().split())
a=int(a[::-1])
b=int(b[::-1])
print(max(a,b))

#2460
tot=0
totli=[]
for i in range(10):
    a,b=map(int,input().split())
    tot-=a
    tot+=b
    totli.append(tot)
print(max(totli))

#2592
tot=mxnum=mxvalue=0
totli=[]
for i in range(10):
    a=int(input())
    tot+=a
    totli.append(a)
for num in totli:
    if totli.count(num) > mxvalue:
        mxnum,mxvalue=num,totli.count(num)
print(tot//10)
print(mxnum)

#2711
for i in range(int(input())):
    a,b=map(str,input().split())
    a=int(a)
    b=list(b)
    del b[a-1]
    for j in range(len(b)):
        print(b[j],end='')
    print()

#2953
tot=[]
for i in range(5):
    a,b,c,d=map(int,input().split())
    tot.append(a+b+c+d)
print(tot.index(max(tot))+1,max(tot))

#1292
a,b=map(int,input().split())
nums=[]
for i in range(1,b+1):
    for j in range(1,i+1):
        nums.append(i)
print(sum(nums[a-1:b]))

3460 못품
j=0
for i in range(int(input())):
    a=int(input())
    b=str(format(a,'b'))
    b=b[::-1]
    for i in b:
        if i=='1':
            print(j,end=' ')
        j+=1

#10807
n=int(input())
nums=list(map(int,input().split()))
tgt=int(input())
cnt=0
for i in nums:
    if i==tgt:
        cnt+=1
print(cnt)

#5054
t=int(input())
for i in range(t):
    n=int(input())
    point = list(map(int, input().split()))
    ans=0
    point.sort()
    for j in range(1,n):
        ans+=point[j]-point[j-1]
    print(ans*2)

#3058
n=int(input())
for i in range(n):
    ev_nums=[]
    nums=list(map(int,input().split()))
    for j in nums:
        if j%2==0:
            ev_nums.append(j)
    print(sum(ev_nums),min(ev_nums))

#10953
for i in range(int(input())):
    a,b=map(int,input().split(','))
    print(a+b)

#11721
s=input()
for i in range(len(s)):
    print(s[i],end='')
    if (i+1)%10==0:
        print()

#9086
for i in range(int(input())):
    s=input()
    print(s[0]+s[len(s)-1])

#11170
n=int(input())
for _ in range(n):
     a,b=map(int,input().split())
     cnt = 0
     for j in range(a,b+1):
         if str(j).count('0')!=0:
             cnt+= str(j).count('0')
     print(cnt)

#1676
n=int(input())
fac=1
cnt=0
for i in range(1,n+1):
    fac*=i
ans=str(fac)
for num in ans[::-1]:
    if num=='0':
        cnt+=1
    else:
        break
print(cnt)

#2743
n=input()
print(len(n))

#11720
n=int(input())
nums=input()
intnums=[]
for i in nums:
    intnums.append(int(i))
print(sum(intnums))

#10821
s=input().split(',')
print(len(s))

#10808
s=input()
alp='abcdefghijklmnopqrstuvwxyz'
cnt=0
li=[0 for _ in range(26)]
for i in alp:
    cnt += 1
    for j in s:
        if i==j:
            li[len(alp[0:cnt])-1]+=1
for k in range(26):
    print(li[k],end=' ')

#2693
n=int(input())
for i in range(n):
    nums=list(map(int,input().split()))
    nums.sort(reverse=True)
    print(nums[2])

#1357
def Rev(a):
    b=str(a)
    return  int(b[::-1])
x,y=map(int,input().split())
print(Rev(Rev(x)+Rev(y)))

#2744
s=input()
new_s=[]
for ch in s:
    if ch.isupper()==False:
        ch=ch.upper()
        new_s.append(ch)
    elif ch.islower()==False:
        ch=ch.lower()
        new_s.append(ch)
for i in range(len(new_s)):
    print(new_s[i],end='')

2822
scores=[[i,int(input())] for i in range(1,9)]
nums=[]
tot=0
scores.sort(key = lambda score:score[1])
for j in range(3,8):
    tot+=scores[j][1]
    nums.append(scores[j][0])
print(tot)
nums.sort()
for k in nums:
    print(k,end=' ')

#2750
n=int(input())
nums=[]
for i in range(n):
    nums.append(int(input()))
nums.sort()
for j in nums:
    print(j)

# 2752
nums=list(map(int,input().split()))
nums.sort()
for i in nums:
    print(i,end=' ')

#5543
ham=[]
bav=[]
for i in range(3):
    ham.append(int(input()))
for j in range(2):
    bav.append(int(input()))
ham.sort()
bav.sort()
print(ham[0]+bav[0]-50)

#2587
nums=[]
for i in range(5):
     nums.append(int(input()))
print(sum(nums)//5)
nums.sort()
print(nums[2])

#1427
s=input()
nums=[]
for j in s:
    nums.append(int(j))
nums.sort(reverse=True)
for k in range(len(nums)):
    print(nums[k],end='')

#5576
w_score=[]
k_score=[]
for i in range(10):
    w_score.append(int(input()))
for j in range(10):
    k_score.append(int(input()))
w_score.sort(reverse=True)
k_score.sort(reverse=True)
print(sum(w_score[0:3]),sum(k_score[0:3]))

#11365
while True:
    s=input()
    if s=='END':
        break
    s=s[::-1]
    print(s)

#10987
st=input()
cnt=0
for ch in st:
    if ch in 'aeiou':
        cnt+=1
print(cnt)

#2902
a=input()
b=''
for ch in a:
    if ch.isupper()==True:
        b+=ch
print(b)

#9076
n=int(input())
mx=mn=0
for i in range(n):
    a=list(map(int,input().split()))
    a.sort()
    a.remove(a[4])
    a.remove(a[0])
    if max(a)-min(a)>=4:
        print('KIN')
    else:
        print(sum(a))

#11654
s=input()
print(ord(s))

#3040
nums=[]
ans=False
for _ in range(9):
    nums.append(int(input()))
    nums.sort()
for i in range(8):
    if ans:
        break
    for j in range(i+1,9):
        if sum(nums)-nums[i]-nums[j] == 100:
            nums.pop(i)
            nums.pop(j-1)

            for k in sorted(nums):
                print(k)
            ans=True
            break

#4458
for _ in range(int(input())):
    st=input()
    for i in range(len(st)):
        if i==0:
            print(st[i].upper(),end='')
        else:
            print(st[i],end='')
    print()

#5800
for i in range(int(input())):
    gap=[]
    scores=list(map(int,input().split()))
    n=scores[0]
    scores.remove(n)
    scores.sort(reverse=True)
    for j in range(1,len(scores)):
        gap.append(scores[j-1]-scores[j])
    print('Class',i+1)
    print('Max %d,'%max(scores),'Min %d,'%min(scores),'Largest gap %d'%max(gap))

#5176
for _ in range(int(input())):
    p,m=map(int,input().split())
    nums=[]
    for i in range(1,p+1):
        nums.append(input())
    nums=list(set(nums))
    print(p-len(nums))

#10773
from collections import deque
tot=deque([])
for i in range(int(input())):
    n=int(input())
    if n!=0:
        tot.append(n)
    else:
        tot.pop()
print(sum(tot))

#3460
for _ in range(int(input())):
    n=int(input())
    n=list(format(n,'b'))
    n.reverse()
    for i in range(len(n)):
        if n[i]=='1':
            print(i,end=' ')

#10870
def fib(n):
    if n<=1:
        return n
    else:
        return (fib(n-1)+fib(n-2))
n=int(input())
print(fib(n))

#1037
n=int(input())
nums=list(map(int,input().split()))
print(max(nums)*min(nums))

#10809
st=input()
alp=list(range(97,123))
for ch in alp:
    print(st.find(chr(ch)),end=' ')

#5218
alp=list(range(97,123))
for _ in range(int(input())):
    s1,s2=input().split()
