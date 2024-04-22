import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int num: arr) {
            if (num % divisor == 0) {
                list.add(num);
            }
        }
        int[] answer;
        if (list.size() == 0) {
            answer = new int[]{-1};
        } else {
            answer = new int[list.size()];
            for (int i = 0; i < list.size(); i++) {
                answer[i] = list.get(i);
            }
            Arrays.sort(answer);
        }
        return answer;
        
    }
}