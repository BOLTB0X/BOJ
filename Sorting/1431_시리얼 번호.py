#입력
import sys
input = lambda :sys.stdin.readline().rstrip()

n=int(input())
ports=[]

for _ in range(n):
    #시리얼 넘버랑 포드를 구분
    siri_num=0
    siri_port=input()
    
    #포트 탐색
    for sp in siri_port:
        #숫자이면
        if sp.isdigit():
            siri_num += int(sp)
    ports.append([siri_port,siri_num])

#정렬
ports.sort(key=lambda x:(len(x[0]),x[1],x[0]))

#출력
for p in ports:
    print(p[0])