##########################################################
import sys
sys.setrecursionlimit(10 ** 6)

def input():
    return sys.stdin.readline()

def hit_btn(panel, y, x):
    for dy, dx in ((0, 0), (0, 1), (1, 0), (0, -1), (-1, 0)):
        ny = y + dy
        nx = x + dx
        if 0 <= ny < 10 and 0 <= nx < 10:
            panel[ny][nx] = (panel[ny][nx] + 1) % 2
        
cb = [[0] * 10 for _ in range(10)]

for i in range(10):
    temp = input().rstrip()
    for j in range(len(temp)):
        if temp[j] == "O":
            cb[i][j] = 1

line_num_one = [101] * (1 << 10)
for case in range(1 << 10):
    cnt = 0
    tmp = [cb[row][:] for row in range(10)]  
    flag = 1
    for j in range(9, -1, -1):
        if case & flag:
            hit_btn(tmp, 0, j)
            cnt += 1
        flag <<= 1

    for i in range(1, 10):
        for j in range(10):
            if tmp[i - 1][j]:
                hit_btn(tmp, i, j)
                cnt += 1

    if sum(tmp[9]) == 0:
        line_num_one[case] = cnt

print(min(line_num_one))