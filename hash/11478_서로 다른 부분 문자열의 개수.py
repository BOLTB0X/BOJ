s = str(input())
result = []

for i in range(len(s)):
    for j in range(i,len(s)):
        result.append(s[i:j + 1])

#set으로 중복 제거 후 길이 출력
print(len(set(result)))