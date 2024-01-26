def solution(brown, yellow):
    answer = []
    tot = brown + yellow
    
    for height in range(3, int(tot ** 0.5) + 1):
        if tot % height:
            continue
        width = tot // height
        if (width - 2) * (height - 2) == yellow:
            answer = width, height
            return answer
            
    