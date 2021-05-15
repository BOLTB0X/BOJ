import sys
input=lambda :sys.stdin.readline().rstrip()
n=int(input())
siri=[]
for _ in range(n):
    siri_num=0
    siri_port=input()
    for i in siri_port:
        if i.isdigit():
            siri_num+=int(i)
    siri.append([siri_port,siri_num])
siri.sort(key=lambda x:(len(x[0]),x[1],x[0]))
for j in siri:
    print(j[0])