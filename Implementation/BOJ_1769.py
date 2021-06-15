#3의 배수
X=input()
temp=X
cnt=0
while len(temp)>=2: #길이가 1일 될때까지 돌린다
    cnt+=1 #카운트 증가
    Y=0
    for x in temp: #temp를 이용해서 길이를 확인한다.
        Y+=int(x)
    temp=str(Y)  #Y로 바꿈
if int(temp)%3==0:
    print(cnt)
    print('YES')
else:
    print(cnt)
    print('NO')

#다른사람의 풀이 재귀이용한 풀이
def solution(X, cnt):
    if len(X)>1: # X가 1보다 크다면
        cnt+=1
        Y=0
        for x in X:
            Y+=int(x)
        X=str(Y) #X를 Y로 교체
        solution(X,cnt) #재귀 호출로 길이를 1로 만든다.
    else:
        if int(X)%3==0:
            print(cnt)
            print('YES')
        else:
            print(cnt)
            print('NO')
X = input() 
cnt = 0 
solution(X, cnt)

