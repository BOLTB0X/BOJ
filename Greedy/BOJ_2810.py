#컵홀더
n=int(input())
data_input=input()
s_cnt=data_input.count('S')
ll_cnt=data_input.count('LL') #LL을 자석 하나로 취급
if ll_cnt>0:
    print(s_cnt+ll_cnt+1)
else:
    print(n)
