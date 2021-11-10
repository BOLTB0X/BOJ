#조합
from itertools import combinations
#입출력
from sys import stdin
#입력 
input = stdin.readline

def check(com):
    for c in com:
        moum_cnt = 0
        cnt = 0
        
        for i in c:
            if i in 'aeiou':
                moum_cnt += 1
            else:
                cnt += 1
        
        #출력 조건
        if moum_cnt >= 1 and cnt >= 2:
            print(''.join(c))
        
l,c = map(int,input().split())
ch = list(map(str,input().split()))

#정렬
ch.sort()

#조합
com = list(combinations(ch,l))

#검사 및 출력
check(com)