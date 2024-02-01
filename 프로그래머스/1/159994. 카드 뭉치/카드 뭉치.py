from collections import deque
def solution(cards1, cards2, goal):
    cards1 = deque(cards1)
    cards2 = deque(cards2)
    answer = 'Yes'
    for target in goal:
        if cards1 and cards1[0] == target:
            cards1.popleft()

        elif cards2 and cards2[0] == target:
            cards2.popleft()
        else:
            answer = 'No'
            break
    
    return answer