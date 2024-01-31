import sys
n = int(sys.stdin.readline().rstrip())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().rstrip().split()))
arr.sort(key = lambda x: (x[0], x[1], x[2]))
dpt = [[0, 0] for _ in range(n + 1)] # 0번 끝나는 시간, 1번 인원 수
dpt[0] = [arr[0][1], arr[0][2]]
for i in range(1, n):
    dpt[i] = [arr[i][1], arr[i][2]]
    temp_one = [0, 0]  # i번째에 시작하는 회의를 진행할 수 있는 것 중 최고
    temp_two = [0, 0]  # i번째에 시작하는 회의를 진행할 수 없는 것 중 최고
    for j in range(i - 1, -1, -1):
        if dpt[j][0] <= arr[i][0]:
            if temp_one[1] <= dpt[j][1]:
                temp_one = dpt[j]
                break
        else:
            if temp_two[1] <= dpt[j][1]:
                temp_two = dpt[j]
    if temp_one[1] + arr[i][2] > temp_two[1]:
        dpt[i] = [arr[i][1], temp_one[1] + arr[i][2]]
    else:
        dpt[i] = temp_two
res = 0
for i in range(n):
    res = max(dpt[i][1], res)

print(res)