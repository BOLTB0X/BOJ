#입출력
from sys import stdin
#입력 
input = stdin.readline

while True:
    st=list(input().split())
    cnt=0

    #첫문자는 대문자로
    check=st[0][0].upper()
    
    #탈출 조건
    if st[0][0]=='#':
        break
    
    #순회
    for i in range(1,len(st)):
        for j in range(len(st[i])):
            #대문자
            if check==st[i][j].upper():
                cnt+=1

    print(st[0][0],cnt)