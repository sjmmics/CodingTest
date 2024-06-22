import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                list.add(i);
            }
        }
        int[] answer = new int[list.size()];
        int idx = 0;
        for (int num: list) {
            answer[idx++] = num;
        }
        return answer;
    }
}