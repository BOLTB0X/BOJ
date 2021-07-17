bar_razor = list(input())
answer = 0 
stack = []

for i in range(len(bar_razor)):
    if bar_razor[i]=='(':
        stack.append('(') #스택에 넣는다.
    
    else: #()이 되면 절단 시작
        if bar_razor[i-1] == '(': # 바로 앞이 '('
            stack.pop() #바로앞 '('은 카운트 제외
            answer += len(stack)
        
        else: # ')'인경우
            stack.pop()
            answer+=1 #하나만 잘림

print(answer) 
