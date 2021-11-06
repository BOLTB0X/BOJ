#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
words=[]

#단어 입력
for i in range(n):
    words.append(input())

#중복제거
words=list(set(words))
#길이 짧은 것 순
result=sorted(words,key=lambda x: (len(x),x))

#출력
for r in result:
    print(r)