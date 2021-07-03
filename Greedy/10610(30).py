from itertools import permutations
num=list(input())

p=permutations(num,len(num))
max_value=0

for i in p:
    temp=""
    for j in range(len(i)):
        temp+=i[j]
    temp=int(temp)
    if (temp%30)==0:
        max_value=max(temp,max_value)

print(max_value if max_value !=0 else -1)