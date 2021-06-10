n,k=map(int,input().split())
m=[[1 for _ in range(i)] for i in range(1,31)] #입력 범위
for i in range(2, 30):
    for j in range(1,i):
        m[i][j] = m[i-1][j-1] + m[i-1][j]
print(m[n-1][k-1])