import sys

input = sys.stdin.readline 

DLTA = ((-1, 1), (0, 1), (1, 1))

def dfs(x, y):
    global r, c, visited, grp
    if y == c - 1:
        return True
    for dx, dy in DLTA:
        nx = x + dx
        ny = y + dy
        if not (0 <= nx < r and 0 <= ny < c):
            continue
        if visited[nx][ny]:
            continue
        if grp[nx][ny] == 'x':
            continue
        visited[nx][ny] = 1
        if dfs(nx, ny):
            return True
        

r, c = map(int, input().rstrip().split())
grp = [[] for _ in range(r)]
for i in range(r):
    grp[i] = list(map(str, input().rstrip()))
visited = [[0] * c for _ in range(r)]
for i in range(r):
    dfs(i, 0)

res = 0
for i in range(r):
    res += visited[i][-1]
    
print(res)
