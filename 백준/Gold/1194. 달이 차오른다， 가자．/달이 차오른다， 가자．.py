import sys
from collections import deque

input = sys.stdin.readline

def get_idx(letter):
    letter = letter.lower()
    ans = ['', 'a', 'b', 'c', 'd', 'e', 'f']
    return ans.index(letter)


DLTA = ((1, 0), (-1, 0), (0, 1), (0, -1))

n, m = map(int, input().rstrip().split())

grp = [[] for _ in range(n)]
for i in range(n):
    grp[i] = list(map(str, input().rstrip()))

for i in range(n):
    for j in range(m):
        if grp[i][j] == '0':
            sx, sy = i, j
            
visited = [[set() for _ in range(m)] for _ in range(n)]
visited[sx][sy].add(1)
que = deque([])
que.append((sx, sy, 1, 0))
res = -1

while que:
    if res != -1:
        break
    x, y, bit, dstc = que.popleft()
    for dx, dy in DLTA:
        nx = x + dx
        ny = y + dy
        if not (0 <= nx < n and 0 <= ny < m):
            continue
        if bit in visited[nx][ny] or grp[nx][ny] == '#':
            continue
        visited[nx][ny].add(bit)
        nxt_bit = bit
        if grp[nx][ny].isupper():
            lock_bit = (1 << (get_idx(grp[nx][ny])))
            if bit & lock_bit != lock_bit:
                continue
        elif grp[nx][ny].islower():
            key_bit = (1 << (get_idx(grp[nx][ny])))
            nxt_bit = bit | key_bit

        if grp[nx][ny] == '1':
            res = dstc + 1
            break
        que.append((nx, ny, nxt_bit, dstc + 1))
        
print(res)