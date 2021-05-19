string=input()
check=0
for i in range(len(string)):
    if string[i]=='U' and check==0:
        check=1
    elif string[i]=='C' and check==1:
        check=2
    elif string[i]=='P' and check==2:
        check=3
    elif string[i]=='C' and check==3:
        check=4
if check==4:
    print('I love UCPC')
else:
    print('I hate UCPC')