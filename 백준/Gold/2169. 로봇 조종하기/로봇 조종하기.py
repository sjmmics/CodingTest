import sys

input = sys.stdin.readline 
DFT = -int(1e12)
n, m = map(int, input().rstrip().split())
og_n, og_m = DFT, DFT
mars = [[] for _ in range(n)]

for i in range(n):
    mars[i] = list(map(int, input().rstrip().split()))
    if m < 3:
        for _ in range(2):
            mars[i].append(0)
if n < 3:
    if m < 3:
        mars.append([0] * (m + 2))
        mars.append([0] * (m + 2))
    else:
        mars.append([0] * m)
        mars.append([0] * m)

if n < 3:
    og_n = n
    n += 2
if m < 3:
    og_m = m
    m += 2

dpt = [[[DFT] * 3 for _ in range(m)] for _ in range(n)]

dpt[0][0][0] = mars[0][0]
for j in range(1, m):
    dpt[0][j][0] = mars[0][j] + dpt[0][j - 1][0]
for i in range(1, n - 1):
    dpt[i][0][0] = mars[i][0] + max(dpt[i - 1][0])
    dpt[i][0][1] = mars[i][0] + max(dpt[i - 1][0])
    dpt[i][-1][2] = mars[i][-1] + max(dpt[i - 1][-1])
    for j in range(1, m):
        dpt[i][j][0] = mars[i][j] + max(max(dpt[i][j - 1][:2]), max(dpt[i - 1][j]))
        dpt[i][j][1] = mars[i][j] + max(dpt[i - 1][j])
    for j in range(m - 2, -1, -1):
        dpt[i][j][2] = mars[i][j] + max(max(dpt[i][j + 1][1:]), max(dpt[i - 1][j]))
for j in range(m):
    dpt[-1][j][1] = mars[-1][j] + max(dpt[-2][j])
dpt[-1][0][0] = mars[-1][0] + max(dpt[-2][0])
for j in range(1, m):
    dpt[-1][j][0] = mars[-1][j] + max(max(dpt[-1][j - 1][:2]), max(dpt[-2][j]))

if og_n != DFT and og_m != DFT:
    print(max(dpt[og_n - 1][og_m - 1]))
elif og_n != DFT and og_m == DFT:
    print(max(dpt[og_n - 1][m - 1]))
elif og_n == DFT and og_m != DFT:
    print(max(dpt[n - 1][og_m - 1]))
elif og_n == DFT and og_m == DFT:
    print(max(dpt[n - 1][m - 1]))