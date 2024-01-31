from collections import deque
import sys
n, m = map(int, sys.stdin.readline().split())
if m > 1:
    arr = list(map(int, sys.stdin.readline().split()))
else:
    arr = [int(sys.stdin.readline().rstrip())]

dq = deque([i for i in range(1, n + 1)])
cnt = 0
for idx in arr:
    while True:
        if dq[0] == idx:
            dq.popleft()
            break
        else:
            if dq.index(idx) < len(dq) / 2:
                while dq[0] != idx:
                    dq.append(dq.popleft())
                    cnt += 1
            else:
                while dq[0] != idx:
                    dq.appendleft(dq.pop())
                    cnt += 1

print(cnt)