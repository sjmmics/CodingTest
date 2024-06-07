import sys

input = sys.stdin.readline  

n, k = map(int, input().rstrip().split())

arr = list(map(int, input().rstrip()))
stk = []
for crr in arr:
    # 스택에 저장한 숫자보다 현재 숫자가 크면
    # 제거할 수 있는 숫자만큼 스택에 있는 숫자제거
    while stk and stk[-1] < crr and k > 0:
        stk.pop()
        k -= 1
    stk.append(crr)
    
for i in range(len(stk)):
    stk[i] = str(stk[i])
# 숫자를 지울만큼 다 지웠으면(k가 0보다 크면) 끝자리수 k만큼 삭제 후 출력
if k > 0:   
    print(''.join(stk[:-k]))
else:
    print(''.join(stk))