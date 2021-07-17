k,n,m=map(int,input().split()) # 과자가격, 개수, 돈 
print(k*n-m if (k*n-m)>0 else 0)