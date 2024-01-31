import sys

input = sys.stdin.readline 

def check(x, y):
    global board, ex, N, M
    ans = 0
    for dx, dy in ((1, 0), (1, 1), (1, -1), (0, 1)):
        temp = [board[x][y]]
        for step in (1, 2, 3):
            nx = x + step * dx
            ny = y + step * dy
            if not (0 <= nx < N and 0 <= ny < M):
                break
            temp.append(board[nx][ny])
        if tuple(temp) in ex:
            ans += 1
    return ans


ex = set()
for fst in ('I', 'E'):
    for scd in ('N', 'S'):
        for trd in ('F', 'T'):
            for fth in ('P', 'J'):
                temp = [fst, scd, trd, fth]
                ex.add(tuple(temp))
                ex.add(tuple(temp[::-1]))

frst_letter = {'I', 'E', 'P', 'J'}

N, M = map(int, input().rstrip().split())
board = [[] for _ in range(N)]
for i in range(N):
    board[i] = list(map(str, input().rstrip()))

res = 0
for i in range(N):
    for j in range(M):
        if board[i][j] not in frst_letter:
            continue    
        res += check(i, j)
        
print(res)