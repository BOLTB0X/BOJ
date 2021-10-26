#입출력
from sys import stdin
#Counter 모듈
from collections import Counter
#입력 
input = stdin.readline

n = int(input())
ngf = [-1 for _ in range(n)]
seq = list(map(int, input().strip().split()))
counter_dict = dict(Counter(seq))
stack = [0]

#순회
for i in range(1, n):
    while stack and counter_dict[seq[stack[-1]]] < counter_dict[seq[i]]:
        ngf[stack.pop()] = seq[i]
    stack.append(i)

#출력
print(*ngf)