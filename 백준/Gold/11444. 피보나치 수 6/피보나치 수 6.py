import sys

input = sys.stdin.readline 

MOD = 1_000_000_007

def mlt_fibo(x, y):
    global MOD
    ans = [[0] * len(y[0]) for _ in range(2)]
    for i in range(2):
        for j in range(len(y[0])):
            tot = 0
            for k in range(2):
                tot += x[i][k] * y[k][j]
            ans[i][j] = tot % MOD
    return ans
    
    
def div_conq(expr, nmbr_sqr):
    if nmbr_sqr == 1:
        return expr
    elif nmbr_sqr % 2:
        return mlt_fibo(div_conq(expr, nmbr_sqr - 1), expr)
    else:
        return div_conq(mlt_fibo(expr, expr), nmbr_sqr // 2)
    
    
mtrx = [[1, 1],
        [1, 0]]

strt = [[1], [1]]

n = int(input().rstrip())
if n > 2:
    print(mlt_fibo(div_conq(mtrx, n - 2), strt)[0][0])
else:
    print(1)
