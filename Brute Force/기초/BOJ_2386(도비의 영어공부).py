while True:
    st=list(input().split())
    cnt=0
    if st[0][0]=='#':
        break
    for i in range(1,len(st)):
        for j in range(len(st[i])):
            if st[0][0]==st[i][j]:
                cnt+=1
    print(st[0][0],cnt)