import sys
input = sys.stdin.readline

n = int(input())
li=[]

for i in range(n):
    a,b = map(int,input().split())
    li.append(a+b)
    
for i in range(n):
    print('Case #%i'%(i+1)+':',li[i])
