import sys

input = sys.stdin.readline

def btrk(x, y, cnt):
    global res
    if y >= 10:
        res = min(res, cnt)
        return

    if x >= 10:
        btrk(0, y + 1, cnt)
        return

    if paper[x][y] == 1:
        for size in range(5):
            if used[size] == 5:
                continue
            if x + size >= 10 or y + size >= 10:
                continue
            flag = False
            for i in range(x, x + size + 1):
                for j in range(y, y + size + 1):
                    if not paper[i][j]:
                        flag = True
                        break
                if flag:
                    break
            if not flag:
                for i in range(x, x + size + 1):
                    for j in range(y, y + size + 1):
                        paper[i][j] = 0

                used[size] += 1
                btrk(x + size + 1, y, cnt + 1)
                used[size] -= 1

                for i in range(x, x + size + 1):
                    for j in range(y, y + size + 1):
                        paper[i][j] = 1
    else:
        btrk(x + 1, y, cnt)


paper = [[] for _ in range(10)]
for i in range(10):
    paper[i] = list(map(int, input().rstrip().split()))
used = [0] * 6
res = int(1e9)
btrk(0, 0, 0)
print(res if res != int(1e9) else -1)