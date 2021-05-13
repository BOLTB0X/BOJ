n=int(input())
words=[]
for i in range(n):
    words.append(input())
words=list(set(words))
ans=sorted(words,key=lambda x: (len(x),x))
for i in ans:
    print(i)