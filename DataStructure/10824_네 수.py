#입출력
from sys import stdin
#입력 
input = stdin.readline

a,b,c,d=map(int,input().split())

ab = str(a) + str(b)
cd = str(c) + str(d)

print(int(ab)+int(cd))