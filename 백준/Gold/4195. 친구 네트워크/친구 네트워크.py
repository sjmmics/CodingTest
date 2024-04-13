import sys

sys.setrecursionlimit(10 ** 6)

def get_prnt(x):
    global prnt
    if prnt[x] == x:
        return x
    prnt[x] = get_prnt(prnt[x])
    return prnt[x]


def union(x, y):
    global prnt
    x, y = get_prnt(x), get_prnt(y) 
    if x != y:
        prnt[x] = y
        friends_num[y] += friends_num[x]
    print(friends_num[y])


t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    prnt = dict()
    friends_num = dict()
    for _ in range(n):
        a, b = map(str, input().rstrip().split())
        if a not in prnt:
            prnt[a] = a
            friends_num[a] = 1
        if b not in prnt:
            prnt[b] = b
            friends_num[b] = 1
        union(a, b)    
