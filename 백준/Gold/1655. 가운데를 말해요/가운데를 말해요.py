import sys
from heapq import heappop
from heapq import heappush

input = sys.stdin.readline 

n = int(input().rstrip())
upper = [] # 최소힙
lower = [] # 최대힙

for _ in range(n):
    x = int(input().rstrip())
    if len(upper) == len(lower):
        heappush(lower, -x)
    else:
        heappush(upper, x)
    
    if upper and -lower[0] > upper[0]:
        smst_upper = heappop(upper)
        bgst_lower = heappop(lower)
        heappush(upper, -bgst_lower)
        heappush(lower, -smst_upper)
    print(-lower[0])