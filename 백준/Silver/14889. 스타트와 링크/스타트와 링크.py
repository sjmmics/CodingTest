import sys
from itertools import combinations

input = sys.stdin.readline 

n = int(input().rstrip())
stats = [[] for _ in range(n)]
for i in range(n):
    stats[i] = list(map(int, input().rstrip().split()))
res = int(1e9)
combi = list(combinations(range(n), n // 2))

for sub_list in combi:
    team_a = 0
    team_b = 0
    indx = [1] * n
    for i in sub_list:
        indx[i] = 0
        for j in sub_list:
            if i != j:
                team_a += stats[i][j]
    for i in range(n):
        for j in range(n):
            if indx[i] and indx[j] and i != j:
                team_b += stats[i][j]
    res = min(res, abs(team_a - team_b))
print(res)