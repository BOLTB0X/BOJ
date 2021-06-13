#A+B-7 https://www.acmicpc.net/problem/11021
n=int(input())
li=[]
for i in range(n):
    a,b=map(int,input().split())
    li.append(a+b)
for i in range(n):
    print('Case #%i'%(i+1)+':',li[i])