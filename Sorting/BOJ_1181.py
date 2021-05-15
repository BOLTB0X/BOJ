#단어 정렬
n=int(input())
words=[]
for i in range(n):
    words.append(input())
words=list(set(words))
ans=sorted(words,key=lambda x: (len(x),x)) #람다식으로 정렬기준 맞춤
for i in ans:
    print(i)
