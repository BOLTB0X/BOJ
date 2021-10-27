#입출력
from sys import stdin

#입력 
input = stdin.readline

T=int(input())

for _ in range(T):
    #좌표 입력
    points=list(map(float,input().split(' ')))
    
    player1 = 0
    player2 = 0
    winner = None

    #2개씩 건너뛰며
    for i in range(0, 12, 2):
        score = 0
        dist = points[i]**2 + points[i+1]**2
       
        if dist <= 9:
            score += 100
        elif 9 < dist <= 36:
            score += 80
        elif 36 < dist <= 81:
            score += 60
        elif 81 < dist <= 144:
            score += 40
        elif 144 < dist <= 225:
            score += 20

        if 0 <= i <= 4:
            player1 += score
        else:
            player2 += score

    if player1 > player2:
        winner = "PLAYER 1 WINS"
    elif player1 < player2:
        winner = "PLAYER 2 WINS"
    else:
        winner = "TIE"

    print(f'SCORE: {player1} to {player2}, {winner}.')
   
