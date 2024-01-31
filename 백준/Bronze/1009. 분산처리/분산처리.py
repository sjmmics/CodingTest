n = int(input())
for _ in range(n):
    x, y = map(int, input().split())
    # a ** b
    str_x, str_y = str(x), str(y)
    if x > 10:
        x = x % (10 ** (len(str_x) - 1))
    else:
        x = x
    if x == 1 or x == 5 or x == 6 or x == 10:
        res = x
    elif x == 2 or x == 3 or x == 7 or x == 8:
        res = x ** (y % 4 if y % 4 != 0 else 4) 
    else:
        res = x ** (y % 2 if y % 2 != 0 else 2)
    
    str_res = str(res)
    print(str_res[-1] if str_res[-1] != '0' else 10)