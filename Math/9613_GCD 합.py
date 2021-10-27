#입출력
from sys import stdin
#입력 
input = stdin.readline

#최대공약수
def gcd(a,b): 
    if a % b == 0:
        return b
    else:
        return gcd(b,a%b)

#길이 입력
n=int(input())

#반복문 시작
for _ in range(n):
    #베열 입력
    arr=list(map(int,input().split()))
    
    tot=0

    for i in range(1,len(arr)):
        for j in range(i+1,len(arr)):
            tot += gcd(arr[i],arr[j])

    #출력
    print(tot)