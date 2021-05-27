#2622 삼각형만들기

#구현_초등부올림피아드
n=int(input())
result=0
for i in range(1,n):
    for j in range(i,n):
        k=n-(i+j)
        if k<j: #i<j<k 순이므로 이러면 중복이니
            break
        if j+i>k:
            result+=1
print(result)