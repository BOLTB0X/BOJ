import sys
input=lambda :sys.stdin.readline().rstrip()
n=int(input())
stu_inf=[]
for i in range(n):
    name,kor,eng,math=input().split()
    stu_inf.append([name,int(kor),int(eng),int(math)])
stu_inf.sort(key=lambda x:(-x[1],x[2],-x[3],x[0]))
for i in stu_inf:
    print(i[0])