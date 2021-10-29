#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())

i=1
result = 0

while i<=n:
    #각 자리수 체크
    result += (n-i+1) 
    i*=10

print(result)