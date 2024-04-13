n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a = sorted(a)
b = sorted(b, reverse=True)
res = []
for i in range(n):
    res.append(a[i] * b[i])
    
print(sum(res))