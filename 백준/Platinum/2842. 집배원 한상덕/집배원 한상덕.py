from collections import deque
import sys

input = sys.stdin.readline 

DLTA = ((0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1))

n = int(input().rstrip())
dlvry = [[] for _ in range(n)]
alttd = [[] for _ in range(n)]
for i in range(n):
    dlvry[i] = list(map(str, input().rstrip()))            
height = []
for i in range(n):
    alttd[i] = list(map(int, input().rstrip().split()))
    height += alttd[i]
height = list(set(height))
height.sort()
span = len(height)
spots = []
smst = int(1e9)
bgst = 0
for i in range(n):
    for j in range(n):
        if dlvry[i][j] == 'P':
            smst = min(smst, alttd[i][j])
            bgst = max(bgst, alttd[i][j])
            spots.append([i, j])
            sx, sy = i, j
        elif dlvry[i][j] == 'K':
            smst = min(smst, alttd[i][j])
            bgst = max(bgst, alttd[i][j])
            spots.append([i, j])

left_idx = 0
right_idx = 0
res = int(1e9)
while height[right_idx] < bgst:
    right_idx += 1

while left_idx <= right_idx < span:
    low = height[left_idx]
    high = height[right_idx]
    if low > smst:
        break
    que = deque([])    
    visited = [[0] * n for _ in range(n)]
    if low <= alttd[sx][sy] <= high:
        visited[sx][sy] = 1
        que.append((sx, sy))
    while que:
        x, y = que.popleft()
        for dx, dy in DLTA:
            nx = x + dx
            ny = y + dy
            if not (0 <= nx < n and 0 <= ny < n):
                continue
            if visited[nx][ny]:
                continue
            if not (low <= alttd[nx][ny] <= high):
                continue
            visited[nx][ny] = 1
            que.append((nx, ny))
    dlvry_cmplt = True
    for r, c in spots:
        if not visited[r][c]:
            dlvry_cmplt = False
            break
            
    if dlvry_cmplt:
        res = min(res, high - low)
        left_idx += 1
        if left_idx > right_idx:
            right_idx += 1
    else:
        right_idx += 1
        
print(res)