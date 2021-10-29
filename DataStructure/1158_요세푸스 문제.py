n, k = map(int, input().split())
 
josephus = [i for i in range(1, n+1)]

#결과
result = []
#제거 될 사람의 번호
idx = 0

for t in range(n):
    idx += k-1  
    # 한바퀴를 돌고 그다음으로 돌아올때를 대비해 값을 나머지로 바꿈  
    if idx >= len(josephus):   
        idx = idx % len(josephus)
 
    result.append(str(josephus.pop(idx)))
print("<",", ".join(result)[:],">", sep='')