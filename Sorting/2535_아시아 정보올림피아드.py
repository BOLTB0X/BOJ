#입력
import sys
input = lambda :sys.stdin.readline().rstrip()

n=int(input())
students=[]

for i in range(n):
    students.append(list(map(int,input().split())))
students.sort(key = lambda x:-x[2])

print(*students[0][:2])
print(*students[1][:2])

if students[0][0]==students[1][0]:
    print(*students[3][:2])
else:
    print(*students[2][:2])