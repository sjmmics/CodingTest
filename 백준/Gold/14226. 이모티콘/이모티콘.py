from collections import deque
import sys

input = sys.stdin.readline 
INF = int(1e9)
S = int(input().rstrip())

vstd = [[INF] * (2 * S + 1) for _ in range(2 * S + 1)]

vstd[1][0] = 0
que = deque([])
que.append((1, 0))

while que:
    mntrd, cpyd = que.popleft()
    if mntrd > 0 and vstd[mntrd - 1][cpyd] > vstd[mntrd][cpyd] + 1:
        vstd[mntrd - 1][cpyd] = vstd[mntrd][cpyd] + 1
        que.append((mntrd - 1, cpyd))
    if vstd[mntrd][mntrd] > vstd[mntrd][cpyd] + 1:
        vstd[mntrd][mntrd] = vstd[mntrd][cpyd] + 1
        que.append((mntrd, mntrd))
    if mntrd + cpyd < (2 * S + 1) and vstd[mntrd + cpyd][cpyd] > vstd[mntrd][cpyd] + 1:
        vstd[mntrd + cpyd][cpyd] = vstd[mntrd][cpyd] + 1
        que.append((mntrd + cpyd, cpyd))
            
print(min(vstd[S]))