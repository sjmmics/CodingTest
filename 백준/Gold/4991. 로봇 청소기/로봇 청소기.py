# 더러운 칸과 시작점 사이의 최단거리를 모두 계산한 후 그 합의 최소값 출력

import sys
from collections import deque
from itertools import permutations


input = sys.stdin.readline

INF = int(1e5)
DLTA = ((1, 0), (-1, 0), (0, 1), (0, -1))
while True:
    w, h = map(int, input().rstrip().split())
    if (w, h) == (0, 0):
        break
    grp = [[] for _ in range(h)]
    for i in range(h):
        grp[i] = list(map(str, input().rstrip()))
    ds = []
    bgn = []
    for i in range(h):
        for j in range(w):
            if grp[i][j] == '*':
                ds.append((i, j))
            elif grp[i][j] == 'o':
                bgn = [(i, j)]
    ds = bgn + ds
    num_ds = len(ds)
    # dstc[a][b] = a -> b로 가는 최단거리 
    dstc = [[0] * (num_ds) for _ in range(num_ds)]
    res = 0
    for i in range(num_ds):
        que = deque([])
        visited = [[INF] * w for _ in range(h)]
        sr, sc = ds[i]
        visited[sr][sc] = 0
        que.append((sr, sc))
        while que:
            x, y = que.popleft()
            for dx, dy in DLTA:
                nx = x + dx
                ny = y + dy
                if not (0 <= nx < h and 0 <= ny < w) or visited[nx][ny] != INF:
                    continue
                if grp[nx][ny] != 'x':
                    visited[nx][ny] = visited[x][y] + 1
                    que.append((nx, ny))
        # 최단거리 배열에 탐색 값 저장
        for j in range(num_ds):
            r, c = ds[j]
            dstc[i][j] = visited[r][c]
    prmu = list(permutations(range(1, num_ds), num_ds - 1))
    res = INF
    for route in prmu:
        temp = 0
        crr = 0
        for nxt in route:
            temp += dstc[crr][nxt]
            crr = nxt
        res = min(res, temp)
        
    print(res if res < INF else -1)
    