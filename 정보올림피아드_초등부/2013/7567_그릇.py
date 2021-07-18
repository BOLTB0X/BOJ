input_data=input()
answer=10
for i in range(1,len(input_data)):
    if input_data[i-1]==input_data[i]:
        answer+=5
    else:
        answer+=10
print(answer)
