a=list(map(int,input().split()))
b=list(map(int,input().split()))
a_score,b_score=0,0
for i in range(10):
    if a[i]>b[i]:
        a_score+=3
    elif a[i]<b[i]:
        b_score+=3
    else:
        a_score+=1
        b_score+=1
print(a_score,b_score)
if a_score > b_score:
    print('A')
elif a_score < b_score:
    print('B')
else:
    cnt=0
    for i in range(9,-1,-1):
        if a[i]>b[i]:
            print('A')
            break
        elif a[i]<b[i]:
            print('B')
            break
        else:
            cnt+=1
    if cnt==10:
        print('D')