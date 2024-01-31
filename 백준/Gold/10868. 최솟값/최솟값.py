import sys
import math

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline 
INF = int(1e9)

def set_sgmt(idx, strt, end):
    global arr, sgmt_min
    if strt == end:
        sgmt_min[idx] = arr[strt]
        return sgmt_min[idx]
    mid = (strt + end) // 2
    sgmt_min[idx] = min(set_sgmt(idx * 2, strt, mid), set_sgmt(idx * 2 + 1, mid + 1, end))
    return sgmt_min[idx]


def get_smst(idx, strt, end, left, right):
    global sgmt_min
    if strt > right or end < left:
        return INF
    
    if left <= strt and end <= right:
        return sgmt_min[idx]
    mid = (strt + end) // 2
    return min(get_smst(idx * 2, strt, mid, left, right), get_smst(idx * 2 + 1, mid + 1, end, left, right))


n, m = map(int, input().rstrip().split())

arr = [0] * n
for i in range(n):
    arr[i] = int(input().rstrip())
height_tree = int(math.ceil(math.log2(n)))
num_node = 1 << (height_tree + 1)

sgmt_min = [0] * num_node
set_sgmt(1, 0, n - 1)

for _ in range(m):
    a, b = map(int, input().rstrip().split())
    ans = get_smst(1, 0, n - 1, a - 1, b - 1)
    print(ans)