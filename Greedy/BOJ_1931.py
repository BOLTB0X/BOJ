#회의실 배정
n=int(input())
room=[]
result=1
for _ in range(n):
    room.append(list(map(int,input().split()))) #룸이란 리스트에 각 시간(리스트로)을 담는다.
room.sort(key=lambda x:(x[1],x[0])) #끝나는 시간을 기준으로 오름차순 정렬
end_time=room[0][1] #가장 첫 번째 원소를 사용하고 이것의 끝나는 시간을 담는다.
for i in range(1,n):
    if room[i][0]>=end_time: #다음 시작하는 시간이 크거나 같으면
        result+=1 #카운트
        end_time=room[i][1] #비교하는 시간도 한칸 증가
print(result)