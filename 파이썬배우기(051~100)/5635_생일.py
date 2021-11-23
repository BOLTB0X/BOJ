import sys
input = sys.stdin.readline

n = int(input())
#학생 리스트
students = []

for _ in range(n):
    name,d,m,y = input().split()
    
    if len(m) == 1:
        m = '0' + m
    if len(d) == 1:
        d = '0' + d
    #학생리스트에 삽입
    students.append((name,y+m+d))

#나이 기준으로 오름차순 정렬
students.sort(key = lambda x: int(x[1]))

#출력
print(students[-1][0])
print(students[0][0])