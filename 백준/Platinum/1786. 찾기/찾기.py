import sys


def kmp(text, pattern):
    tb = [0] * len(pattern)
    idx = 0
    for j in range(1, len(pattern)):
        while idx > 0 and pattern[idx] != pattern[j]:
            idx = tb[idx - 1]
        if pattern[idx] == pattern[j]:
            idx += 1
            tb[j] = idx

    res = []
    i = 0
    for k in range(len(text)):
        while i > 0 and pattern[i] != text[k]:
            i = tb[i - 1]
        if pattern[i] == text[k]:
            i += 1
            if i == len(pattern):
                res.append(k - i + 2)
                i = tb[i - 1]
    
    return res

t = str(sys.stdin.readline().replace('\n', ''))
p = str(sys.stdin.readline().replace('\n', ''))

result = kmp(t, p)
print(len(result))
print(*result)