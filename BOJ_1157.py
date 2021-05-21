
s=input().upper()
dic={}
for i in s:
    if i in dic:
        dic[i]+=1
    else:
        dic[i]=1
max_alp=0
for i in dic:
    if dic[i]>max_alp:
        max_alp=dic[i]
        ans=i
    elif dic[i]==max_alp:
        ans='?'
print(ans)