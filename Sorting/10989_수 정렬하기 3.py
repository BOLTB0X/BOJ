#입출력
from sys import stdin
#입력 
input = stdin.readline
check_list = [0] * 10001

n=int(input())
nums=[]

for i in range(n): 
    num = int(input()) 
    check_list[num] = check_list[num] + 1 
    
for i in range(10001): 
    if check_list[i] != 0: 
        for j in range(check_list[i]): 
            print(i)
