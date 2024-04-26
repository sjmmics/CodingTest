import java.util.Collections;
import java.util.Arrays;

class Solution {
    public int solution(int k, int m, int[] score) {
        Integer[] scoreArr = Arrays.stream(score).boxed().toArray(Integer[]::new);
        Arrays.sort(scoreArr, Collections.reverseOrder());
        int answer = 0;
        for (int i = m - 1; i < scoreArr.length; i+=m) {
            answer += scoreArr[i] * m;
        }
        
        return answer;
    }
}

// 1, 1, 1, 2, 2, 3, 3
// 3, 3, 2, 2, 1, 1, 1
// 0, 1, 2, 3, 4, 5, 6
// 1, 2, 3, 4, 5, 6,