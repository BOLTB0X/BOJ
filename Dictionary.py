#딕셔너리란?
fruit=["사과","사과","바나나","바나나","딸기","키위","복숭아","복숭아","복숭이"]
dic={}

for f in fruit:
    if f in dic:
        dic[f]+=1 #value 1증가
    else:
        dic[f]=1 #f가 key 1이 value
print(dic)

