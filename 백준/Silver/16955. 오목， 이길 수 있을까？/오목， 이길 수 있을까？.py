import sys

input = sys.stdin.readline 

DLTA = ((1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1))

board = [[] for _ in range(10)]
for i in range(10):
    board[i] = list(map(str, input().rstrip()))

flag = False
res = 0
for x in range(10):
    if flag:
        break
    for y in range(10):
        if flag:
            break
        if board[x][y] != 'O':
            if board[x][y] == '.':
                empty_og = 1
                check_og = 0
            elif board[x][y] == 'X':
                empty_og = 0
                check_og = 1
            for dx, dy in DLTA:
                empty = empty_og
                check = check_og
                for step in range(1, 4 + 1):
                    nx = x + dx * step
                    ny = y + dy * step
                    if not (0 <= nx < 10 and 0 <= ny < 10):
                        break
                    if board[nx][ny] == 'X':
                        check += 1
                    elif board[nx][ny] == '.':
                        empty += 1
                    elif board[nx][ny] == 'O':
                        break
                if check == 4 and empty == 1:
                    res = 1
                    flag = True
                    break
                
print(res)