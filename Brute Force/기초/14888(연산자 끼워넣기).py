n=int(input())
nums=list(map(int,input().split()))
add,sub,mul,div=map(int,input().split())
# + - * // 

min_v=1000000001
max_v=-1000000001

def cal(num,idx,add,sub,mul,div):
    global n, max_v, min_v
    if idx == n:
        max_v=max(num, max_v)
        min_v=min(num, min_v)
        return
    else:
        if add > 0:
            cal(num + nums[idx], idx + 1, add - 1, sub, mul, div)
        if sub > 0:
            cal(num - nums[idx], idx + 1, add, sub - 1, mul, div)
        if mul > 0:
            cal(num * nums[idx], idx + 1, add, sub , mul -1, div)
        if div > 0:
            cal(int(num / nums[idx]), idx + 1, add, sub, mul, div -1)

cal(nums[0],1,add,sub,mul,div)
print(max_v)
print(min_v)