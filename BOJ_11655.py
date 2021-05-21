s=input()
ans=''
for i in range(len(s)):
    if s[i].isupper():
        tran_s=chr((ord(s[i])+13) if s[i] <='M' else ord(s[i])-13)
        ans+=tran_s
    elif s[i].islower():
        tran_s=chr((ord(s[i])+13) if s[i] <='m' else ord(s[i])-13)
        ans+=tran_s
    else:
        ans+=s[i]
print(ans)