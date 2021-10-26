#입출력
from sys import stdin

#입력 
input = stdin.readline

T=int(input())

for _ in range(T):
    #단어들 입력
    words=list(input().split())
    #파이썬 기능 이용
    for word in words:
        print(word[::-1],end=' ')
    print()