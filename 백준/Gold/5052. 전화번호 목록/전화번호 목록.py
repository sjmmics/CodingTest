import sys

input = sys.stdin.readline 

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    arr = [''] * n
    for i in range(n):
        arr[i] = str(input().rstrip())
    arr.sort()
    cnst_flag = True
    for i in range(n - 1):
        span = len(arr[i])
        if arr[i] == arr[i + 1][:span]:
            cnst_flag = False
            break
    if cnst_flag:
        print('YES')
    else:
        print('NO')