board_char = [[0] * 15 for i in range(5)] #각 글자수를 저장하는 리스트

for i in range(5): #행은 5이므로 
    string = list(input())
    string_len = len(string)
    for j in range(string_len): #글자수를 저장 가능
         board_char[i][j] = string[j]

for i in range(15):
    for j in range(5):
        if board_char[j][i] == 0:
            continue;
        else:
            print(board_char[j][i], end='')
print()