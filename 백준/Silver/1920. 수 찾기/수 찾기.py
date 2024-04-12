import sys

n = int(input())
n_dict = dict()

n_list = list(map(int, sys.stdin.readline().split()))
for j in n_list:
    n_dict[j] = 1
    
m = int(input())
m_list = list(map(int, sys.stdin.readline().split()))
for k in m_list:
    print(n_dict.get(k, 0))