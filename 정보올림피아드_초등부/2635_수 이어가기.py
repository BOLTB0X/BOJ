n = int(input())

#최대 길이, 최대길이 리스트
max_len = 0
max_arr = 0

for i in range(n+1):
    result = [n,i]
    j=0
    
    while(True):
        #해당값 조회
        ele = result[j] - result[j+1]
        
        #음수가 등장하면
        if ele <= -1:
            #탈출
            break
        
        #삽입
        result.append(ele)

        #최대인지 체크
        if max_len < len(result):
            max_len = len(result)
            max_arr = result
        
        #증가
        j += 1

#출력
print(max_len)
print(*max_arr)