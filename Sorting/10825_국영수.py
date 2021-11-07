#입출력
from sys import stdin
#입력 
input = stdin.readline

t=int(input())
scores=[]

for i in range(t):
    student,kor,eng,mat=input().split()
    scores.append([student,int(kor),int(eng),int(mat)])

#정렬
scores.sort(key = lambda x: (-x[1],x[2],-x[3],x[0]))

#출력
for s in scores:
    print(s[0])