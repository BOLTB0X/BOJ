n=int(input())
words=[]

for i in range(n):
    word = input()
    word_len = len(word)
    words.append((word,word_len))

#중복 제거
words=list(set(words))
#길이 짧은 순 그 다음 알파벳 
words.sort(key=lambda word : (word[1] , word[0]))

#출력
for word in words:
    print(word[0])