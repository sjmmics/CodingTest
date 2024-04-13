import sys
from collections import deque

input = sys.stdin.readline 

def bfs(a, b, c, d):
    global N, M, K, grp
    DLTA = ((1, 0), (-1, 0), (0, 1), (0, -1))
    vstd = [[-1] * M for _ in range(N)]
    vstd[x1][y1] = 0
    que = deque([])
    que.append((a, b))
    while que:
        x, y = que.popleft()
        if (x, y) == (c, d):
            return vstd[x][y]
        for dx, dy in DLTA:
            for step in range(1, K + 1):
                nx = x + step * dx
                ny = y + step * dy
                if not (0 <= nx < N and 0 <= ny < M) or grp[nx][ny] == '#':
                    break
                   
                if vstd[nx][ny] == -1:
                    vstd[nx][ny] = vstd[x][y] + 1
                    que.append((nx, ny))
                elif vstd[nx][ny] > vstd[x][y]:
                    continue
                else:
                    break
    return -1


N, M, K = map(int, input().rstrip().split())

grp = [[] for _ in range(N)]
for i in range(N):
    grp[i] = list(map(str, input().rstrip()))
    
temp = list(map(int, input().rstrip().split()))
for i in range(4):
    temp[i] -= 1
    
x1, y1, x2, y2 = temp

print(bfs(x1, y1, x2, y2))