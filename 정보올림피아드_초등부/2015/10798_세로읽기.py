board_char = [[0] * 15 for i in range(5)] #각 글자수를 저장하는 리스트

for i in range(5): #행은 5이므로 
    string = list(input())
    
    for j in range(len(string)): #글자수를 저장 가능
         board_char[i][j] = string[j] #저장 i번째 행의 열 원소들이 천천히 저장 리스트에 담김

for i in range(15):
    for j in range(5):
        if board_char[j][i] == 0:
            continue;
        else:
            print(board_char[j][i], end='') # [1][1] [2][1] [3][1] 으로 출력
print()
