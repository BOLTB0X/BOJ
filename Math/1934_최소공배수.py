#입출력
from sys import stdin
#입력 
input = stdin.readline

for i in range(int(input())):
    a,b=map(int,input().split())
    x=a
    y=b
    
    #재귀가 아닌 반복문
    while b !=0:
        r=a%b
        a=b
        b=r
    
    lcd=x*y/a
    
    #출력
    print(int(lcd))