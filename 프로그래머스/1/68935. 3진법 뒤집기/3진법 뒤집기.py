def trans(x):
    ans = ""
    while x >= 3:
        ans = str(x % 3) + ans
        x //= 3
    return str(x) + ans

def backTen(x):
    ans = 0
    span = len(x)
    for i in range(span):
        ans += int(x[i]) * (3 ** (span - 1 - i))
    return ans
def solution(n):
    n = trans(n)
    n = n[::-1]
    answer = backTen(n)
    return answer