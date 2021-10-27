#입출력
from sys import stdin
#입력 
input = stdin.readline

a,b,c=map(int,input().split())

#출력
print((a+b)%c) 
print(((a%c) + (b%c))%c)
print((a*b)%c)
print(((a%c)*(b%c))%c) 