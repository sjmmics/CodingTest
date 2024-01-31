def cnt_mul(x, mod):
    if x < mod:
        return 0
    ans = 0
    while x >= mod:
        ans += x // mod
        x //= mod
    return ans


n, m = map(int, input().rstrip().split())

cnt_two = cnt_mul(n, 2) - cnt_mul(n - m, 2) - cnt_mul(m, 2)
cnt_five = cnt_mul(n, 5) - cnt_mul(n - m, 5) - cnt_mul(m, 5)

print(min(cnt_two, cnt_five))
