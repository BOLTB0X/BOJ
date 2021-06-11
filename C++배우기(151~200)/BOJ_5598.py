def transFunction(st):
    trans_st1=int(ord(st))-3
    trans_st2=chr(trans_st1)
    return str(trans_st2)
st=input()
answer=[]
for s in st:
    answer.append(transFunction(s))
print(*answer,sep='')