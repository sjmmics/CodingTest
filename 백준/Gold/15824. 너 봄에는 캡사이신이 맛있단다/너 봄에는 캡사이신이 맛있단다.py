import sys

MOD = 1_000_000_007
input = sys.stdin.readline 

def pow(a, b):
    if b == 0:
        return 1
    if b == 1:
        return a
    half = pow(a, b // 2)
    if not b % 2:
        ans = half * half % MOD
    else:
        ans = half * half * a % MOD
    return ans

N = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
arr.sort()
res = 0
 
for i in range(N):
    res += arr[i] * (pow(2, i) - pow(2, N - i - 1))
 
print(res % MOD)