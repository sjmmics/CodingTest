import sys
input = sys.stdin.readline 

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
arr.sort()
res = 1
for num in arr:
    if res < num:
        break
    res += num
    
print(res)