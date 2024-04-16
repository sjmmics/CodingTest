import sys 

input = sys.stdin.readline 
n = int(input().rstrip())
k = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
arr = set(arr)
arr = list(arr)
arr.sort()
# 각 센서의 위치의 차이를 diff에 저장
diff = []
for i in range(1, len(arr)):
    diff.append(arr[i] - arr[i - 1])
    
diff.sort()
# diff에서 가장 큰 것부터 차례대로 (k - 1)개 제거
for _ in range(k - 1):
    if diff:
        diff.pop()

print(sum(diff))