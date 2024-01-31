import sys
import bisect

input = sys.stdin.readline 
t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    arr = [0] * n
    for i in range(n):
        arr[i] = int(input().rstrip())
    dpt = [arr[0]]
    for i in range(n):
        if arr[i] > dpt[-1]:
            dpt.append(arr[i])
        else:
            idx = bisect.bisect_left(dpt, arr[i])
            dpt[idx] = arr[i]

    print(len(dpt))